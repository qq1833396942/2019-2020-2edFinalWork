#include <io.h>
#include <direct.h>
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <queue>
#include <regex>

#include <ws2tcpip.h>
#include <wininet.h>
#include <winsock2.h>
#include <windows.h>


#include <direct.h>
#include "crawlerthread.h" //子线程相关
#include "crawler.h"       //接口函数及变量

#define MAXBUFSIZE 8388608  // 2^20

using namespace std;

//将网址分成主机名和资源名
static pair<string, string> spliturl(const string &url);  
static string crawl(const string &url);               //爬取一个网站的源码
static string GetHostByName(const string &HostName);  //通过主机名获得ip地址
static SOCKET MakeSocket(string ip);                  //创建一个socket并连接到主机
//发送数据
static bool SendPacket(SOCKET sock, const string &hostname, const string &source);
static string RecvPacket(SOCKET sock);         //接受数据

// static void SaveData(const string &url, const string
// &buf);//将url和buf和buf中的中文分别保存到文件中

//解析HTML，将链接加入queue，将资源展开到末尾
static void ParseHTML(string &buf);  

static set<string> visitedurls;  //记录已经访问过的网站
static queue<string> urls;       //要访问的网站
static string filepath = "html\\";
static string textpath = "text\\";
static string urlpath = "url\\";
static int filecount = 0;  //记录创建的文件个数
static pair<string, string> pair_result;
static string hostname;

/* pagerank 相关 */
// static bool matrix[MAXFILECOUNT][MAXFILECOUNT];//邻接矩阵
// string website[MAXFILECOUNT + 1];//编号为i的网站的网址
// static double pr[MAXFILECOUNT] = { 1 };//网址的pagerank值
// static int in_degree[MAXFILECOUNT];//网址的入度
// static int out_degree[MAXFILECOUNT];//网址的出度

static bool **matrix;  //邻接矩阵
string *website;       //编号为i的网站的网址
static double *pr;     //网址的pagerank值
static double *last_pr;
static int *in_degree;   //网址的入度
static int *out_degree;  //网址的出度

string get_url(int i) { return website[i]; }

double get_pr(int i) { return pr[i]; }

int get_in_degree(int i) { return in_degree[i]; }

int init_website(string entry, int MAXFILECOUNT) {
    string filename;
    cout << "filename=" << filename << endl;
    int i;
    for (i = 0; i < MAXFILECOUNT; ++i) {
        filename = entry + "/url/" + to_string(i) + ".txt";
        ifstream ifs(filename);
        if (ifs.fail()) {
            break;
        }
        getline(ifs, website[i]);
        ifs.close();
    }
    filecount = i;
    return i;
}

void init_global_vars(int MAXFILECOUNT) {
    matrix = new bool *[MAXFILECOUNT];
    for (int i = 0; i < MAXFILECOUNT; ++i) matrix[i] = new bool[MAXFILECOUNT];
    for (int i = 0; i < MAXFILECOUNT; ++i)
        for (int j = 0; j < MAXFILECOUNT; ++j) matrix[i][j] = false;
    website = new string[MAXFILECOUNT];
    pr = new double[MAXFILECOUNT];
    last_pr = new double[MAXFILECOUNT];
    for (int i = 0; i < MAXFILECOUNT; ++i) {
        pr[i] = 1;
        last_pr[i] = 1;
    }
    in_degree = new int[MAXFILECOUNT];
    out_degree = new int[MAXFILECOUNT];
    for (int i = 0; i < MAXFILECOUNT; ++i) {
        in_degree[i] = 0;
        out_degree[i] = 0;
    }
}

int CrawlerThread::crawler() {

    string stdentry = entry.toStdString();
    //文件夹存在则覆盖，不存在则创建文件夹
    if (_access(stdentry.c_str(), 0) != -1) {
        _rmdir(stdentry.c_str());
        _mkdir(stdentry.c_str());
    } else
        _mkdir(stdentry.c_str());

    //创建文件夹
    _mkdir((stdentry + "\\" + "html").c_str());
    _mkdir((stdentry + "\\" + "text").c_str());
    _mkdir((stdentry + "\\" + "url").c_str());

    filepath = stdentry + "\\" + filepath;
    textpath = stdentry + "\\" + textpath;
    urlpath = stdentry + "\\" + urlpath;


    //初始化 Windows Sockets
    WSADATA wsadata;
    if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0) {
        emit crawlWarning(
            tr("启动失败"),
            tr("WSA启动失败"));  //仅仅是显示警告信息，可以直接注释掉，最后要加上
        return -1;
    }

    //起始网址插入
    urls.push(stdentry);

    //开始爬
    crawler_start();

    //结束
    WSACleanup();

    //初始化 入度出度计算矩阵
    init_matrix(MAXFILECOUNT);

    pagerank(MAXFILECOUNT);

    return filecount;
}

void CrawlerThread::crawler_start() {
    /* 在此限定主机名
    pair <string, string> temp = spliturl(urls.front());
    hostname = GetHostByName(temp.first);*/

    qDebug()<<entry;

    emit crawlBrowserAppend(
        QObject::tr("正在爬取澎湃新闻数据，网站爬取中......"));

    while (!urls.empty()) {
        if (filecount >= MAXFILECOUNT) {
            break;
        }
        qDebug()<<QString::fromStdString(urls.front());

        /* 进行一些过滤

*/
        if (urls.front().find(".css") != string::npos||
                urls.front().find("channel_") != string::npos||
                urls.front().find("list_") != string::npos||
                urls.front().find(".ico") != string::npos||
                urls.front().find(".jsp") != string::npos||
                urls.front().find("javascript") != string::npos||
                urls.front().find("12377") != string::npos||
                urls.front().find("itunes") != string::npos||
                urls.front().find("//") != string::npos
                ){
            urls.pop();
            continue;
        }

        string buf = crawl(urls.front());

//        qDebug()<<"urls.front()";
//        qDebug()<<QString::fromStdString(urls.front());

//        qDebug()<<"buf\n";
//        qDebug()<<QString::fromStdString(buf);

        if (!buf.empty()) {
            ParseHTML(buf);
            qDebug()<<"buf\n";
            qDebug()<<QString::fromStdString(buf);
            //打印访问过的网站
            emit crawlBrowserAppend(
                QObject::tr("%1").arg(QString::fromStdString(urls.front())));

            SaveData(urls.front(), buf);
            visitedurls.insert(urls.front());
        }
        urls.pop();
    }
}

static string crawl(const string &url) {
    pair_result = spliturl(url);

    /* 获得ip */
    string ip = GetHostByName(pair_result.first);
    //	if (ip.empty() || ip != hostname){
    if (ip.empty()) {
        //找不到ip过滤
        return "";
    }

    /* 连接服务器 */
    SOCKET sock = MakeSocket(ip);
    if (sock == 0) {
        closesocket(sock);
        return "";
    }

    /* 发送请求 */
    if (!SendPacket(sock, pair_result.first, pair_result.second)) {
        closesocket(sock);
        return "";
    }

    /* 收包 */
    string buf = RecvPacket(sock);
    if (buf.empty()) {
        closesocket(sock);
        return "";
    }

    closesocket(sock);

    /* 请求不正确 */
    if (buf.find("Bad Request") != string::npos) {
        return "";
    }

    return buf;
}

static string GetHostByName(const string &HostName) {
    hostent *host = gethostbyname(HostName.c_str());
    if (!host) {
        return "";
    }
    return inet_ntoa(*(in_addr *)host->h_addr);
    // return inet_ntop(host->h_addrtype, host->h_addr, str, 32);
}

static pair<string, string> spliturl(const string &url) {
    int pos;
    pair<string, string> result(url, "");
    pos = url.find("/");
    if (pos != string::npos) {
        result.first = url.substr(0, pos);
        result.second = url.substr(pos + 1);
    }
    return result;
}

static void ParseHTML(string &buf) {
    string temp;

    /* 找到网站中的资源（表格、文字）并展开到buf末尾 */
    char *tag = "<iframe>";
    int pos = buf.find(tag, 0);
    if (pos != string::npos) {
        tag = "src='";
        pos = buf.find(tag, pos);
        if (pos != string::npos) {
            pos += strlen(tag);
            int end = buf.find("'", pos);
            string url = buf.substr(pos, end - pos);
            temp = crawl(pair_result.first + "/" + url);
            pos = temp.find("Content-Length:", 0);
            if (pos != string::npos) {
                pos = temp.find("<", pos);
                if (pos != string::npos)
                    buf += temp.substr(pos, temp.length() - pos);
                else
                    ;
            } else
                ;
        }
    }

    /* 找出网址并加入队列 */
    /* pagerank时需要加东西 */
    for (int i = 0; i < 2; ++i) {
        if (i == 0)
            tag = "href='";
        else
            tag = "href=\"";
        pos = buf.find(tag, 0);
        while (pos != string::npos) {
            pos += strlen(tag);
            int end;
            if (i == 0)
                end = buf.find("'", pos);
            else
                end = buf.find("\"", pos);
            string url = buf.substr(pos, end - pos);

            if (url.find("http://") == string::npos &&
                url.find("https://") == string::npos &&
                url.find(".css") == string::npos) {
                url = pair_result.first + "/" + url;
                if (visitedurls.count(url))
                    ;
                else
                    urls.push(url);
            }

            else if (url.find("http://") != string::npos &&
                     url.find("https://") == string::npos) {
                int pos = url.find("http://") + 7;
                url = url.substr(pos);
                urls.push(url);
            }

            else if (url.find("https://") != string::npos &&
                     url.find("http://") == string::npos) {
                int pos = url.find("https://") + 8;
                url = url.substr(pos);
                urls.push(url);
            }
            pos = buf.find(tag, end);
        }
    }
}

static bool SendPacket(SOCKET sock, const string &hostname,
                       const string &source) {
    string http = "GET " + ("/" + source) + " HTTP/1.1\r\n" +
                  "HOST: " + hostname + "\r\n" + "Connection: close\r\n\r\n";
    if (send(sock, http.c_str(), http.length(), 0) == SOCKET_ERROR)
        return false;
    else
        return true;
}

static string RecvPacket(SOCKET sock) {
    string buf(MAXBUFSIZE, '\0');
    int len = 0;
    int reclen = 0;
    do {
        reclen = recv(sock, &buf[0] + len, MAXBUFSIZE - len, 0);
        len += reclen;
    } while (reclen > 0);

    return buf.substr(0, len);
}

static SOCKET MakeSocket(string ip) {
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET) {
        //		cout << "invalid socket" << endl;
        return 0;
    }

    SOCKADDR_IN addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);
    addr.sin_addr.s_addr = inet_addr(ip.c_str());
    if (connect(sock, (sockaddr *)&addr, sizeof(addr)) == SOCKET_ERROR) {
        //		cout << "failed to connect to " << url << endl;
        return 0;
    }
    return sock;
}

void CrawlerThread::SaveData(const string &url, const string &buf) {
    if (!buf.empty()) {
        /* 将buf存入html下 */
        string filename = filepath + to_string(filecount) + ".txt";
        ofstream ofs(filename);
        //除去buf头的那段信息描述再存入
        int pos = buf.find("<!DOCTYPE");
        if (pos == string::npos) {
            ofs.close();
            return;
        }
        ofs << buf.substr(pos);
        ofs.close();

        website[filecount] = url;

        /* 将buf中的中文挑出并存入text下 */
        filename = textpath + to_string(filecount) + ".txt";
        ofs.open(filename);
        for (unsigned i = 0; i < buf.size(); i++) {
            if (buf.find("font", i) == i) {
                i += 4;
                i = buf.find(";", i);
            } else if (!(buf[i] >= 0 && buf[i] <= 127)) {
                ofs << buf[i];
            }
        }

        ofs.close();

        /* 将网址存入url下 */
        filename = urlpath + to_string(filecount) + ".txt";
        ofs.open(filename);
        ofs << url << endl;
        ofs.close();
        filecount++;
        emit crawlProgress(filecount);  //为进度条使用，可以先注释掉，最后要加上
    }
}

void init_matrix(int MAXFILECOUNT) {
    char *tag;
    int pos;
    for (int i = 0; i < filecount; ++i) {
        /* 读取html文件的全部内容，保存在buf中 */
        pair_result = spliturl(website[i]);
        string filename = filepath + to_string(i) + ".txt";
        ifstream in(filename, ios::in);
        istreambuf_iterator<char> beg(in), end;
        string buf(beg, end);
        in.close();
        /*两次循环查找buf中链接*/
        for (int k = 0; k < 2; ++k) {
            if (k == 0)
                tag = "href='";
            else
                tag = "href=\"";
            pos = buf.find(tag, 0);

            /* 找到buf中的全部网址 */
            while (pos != string::npos) {
                pos += strlen(tag);
                int end;
                if (k == 0)
                    end = buf.find("'", pos);
                else
                    end = buf.find("\"", pos);
                string url = buf.substr(pos, end - pos);

                if (url.find("http://") == string::npos &&
                    url.find("https://") == string::npos &&
                    url.find(".css") == string::npos) {
                    url = pair_result.first + "/" + url;
                }

                else if (url.find("http://") != string::npos &&
                         url.find("https://") == string::npos) {
                    int pos = url.find("http://") + 7;
                    url = url.substr(pos);
                }

                else if (url.find("https://") != string::npos &&
                         url.find("http://") == string::npos) {
                    int pos = url.find("https://") + 8;
                    url = url.substr(pos);
                }
                /* 顺序查找website中的网址 */
                int j;
                for (j = 0; j < filecount; ++j) {
                    if (j == i) continue;
                    if (website[j] == url) break;
                }
                /* 找到，则对应入度出度+1，修改邻接矩阵 */
                if (j != MAXFILECOUNT && matrix[i][j] == false) {
                    matrix[i][j] = true;
                    in_degree[j]++;
                    out_degree[i]++;
                }

                pos = buf.find(tag, end);
            }
        }
    }
}

void pagerank(int MAXFILECOUNT) {
    double last_pr[MAXFILECOUNT];
    double damping_factor = 0.85;
    for (int iteration_times = 0; iteration_times < 100; ++iteration_times) {
        for (int i = 0; i < filecount; ++i) {
            last_pr[i] = pr[i];
            pr[i] = 0;
        }
        for (int i = 0; i < filecount; ++i) {
            for (int j = 0; j < filecount; ++j) {
                if (j == i) continue;
                if (matrix[i][j]) {  //这个网页指向另一个网页
                    pr[j] += last_pr[i] / out_degree[i];
                }
            }
        }
        for (int i = 0; i < filecount; ++i)
            pr[i] = (pr[i] * damping_factor + (1 - damping_factor) / filecount);
    }
    for (int i = 0; i < filecount; ++i) {
        string filename = urlpath + to_string(i) + ".txt";
        ofstream ofs(filename, ios::app);
        ofs << std::fixed << pr[i] << endl;
        ofs << "in = " << in_degree[i] << " out = " << out_degree[i] << endl;
    }
}

void sort_by_pagerank(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        int max = i;
        for (int j = i; j < size; ++j)
            if (pr[arr[j]] > pr[arr[max]]) max = j;
        int temp = arr[max];
        arr[max] = arr[i];
        arr[i] = temp;
    }
}

void sort_by_in_degree(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        int max = i;
        for (int j = i; j < size; ++j)
            if (in_degree[arr[j]] > in_degree[arr[max]]) max = j;
        int temp = arr[max];
        arr[max] = arr[i];
        arr[i] = temp;
    }
}
