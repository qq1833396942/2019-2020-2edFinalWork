#include <direct.h>
#include <windows.h>

#include <QBrush>
#include <QDebug>
#include <QDesktopServices>
#include <QFile>
#include <QFont>
#include <QMessageBox>
#include <QUrl>

#include "crawler.h"
#include "rid.h"
#include "ui_widget.h"
#include "widget.h"

const QString webSiteName = "thepaper.cn";
const QString webSiteGet  = "100";

void Widget::slotCrawlWarning(const QString &title, const QString &content) {
    QMessageBox::warning(this, title, content);
}

void Widget::slotShowProgress(int p) {
    qDebug() << "slot progress:" << p << endl;
    ui->progressBar->setValue(p);
}

void Widget::slotCrawlQuestion(const QString &title, const QString &content,
                               int &ret) {
    if (QMessageBox::question(this, title, content,
                              QMessageBox::Yes | QMessageBox::No))
        ret = 1;
    else
        ret = 0;
}

void Widget::slotCrawlBrowserAppend(const QString &str) {
    ui->textBrowser->append(str);
}

void Widget::slotCrawlComplete(int pageCount) {
    working = false;
    pageNumber = pageCount;
    // pageNumber = 100;//用于测试
    if (pageNumber >= 0)
        QMessageBox::information(this, tr("爬虫"),
                                 tr("从站点%1获取数据已完成，共得到%2个网页")
                                     .arg(webSiteName)
                                     .arg(pageNumber));
    else
        QMessageBox::warning(
            this, tr("爬虫"),
            tr("从站点%1获取数据失败").arg(webSiteName));

    //分词
    divide_text();

    //倒排索引初始化
    init_rid();
}
