#include<iostream>
using namespace std;
const int p = 5;//进程数
const int r = 3;//资源种类

void Apply(int allo[p][r], int need[p][r], int ava[r], int req[r], int n);
bool IsSafe(int allo[p][r], int need[p][r], int ava[r]);
bool com(int m[r], int n[r]);

int main()
{
	int allocation[p][r], need[p][r];
	int available[r], request[r];

	cout << " 输入每个进程已分配的资源数据" << endl;;
	for (int i = 0; i < p; i++)
		for (int j = 0; j < r; j++)cin >> allocation[i][j];
	cout << " 输入每个进程还需要的资源数据" << endl;;
	for (int i = 0; i < p; i++)
		for (int j = 0; j < r; j++)cin >> need[i][j];
	cout << "输入可用的资源数据" << endl;;
	for (int j = 0; j < r; j++)cin >> available[j];

	if (IsSafe(allocation, need, available))cout << "初始状态安全" << endl;
	else cout << "初始状态不安全" << endl;
	while (true)
	{
		cout << " 输入申请的资源" << endl;
		for (int i = 0; i < r; i++)cin >> request[i];

		cout << "第n个进程申请资源——n的值" << endl;;
		int n;
		cin >> n;

		Apply(allocation, need, available, request, n);
	}
	return 0;
}
/*比較函数*/
bool com(int m[r], int n[r])
{
	for (int i = 0; i < r; i++)
	{
		if (m[i] < n[i]) return(0);
	}
	return true;
}

/*安全性检验函数*/
bool IsSafe(int allo[p][r], int need[p][r], int ava[r])
{
	bool  finish[p];
	for (int i = 0; i < p; i++)finish[i] = false;//finish为true即表示available满足某一进程
	for (int i = 0; i < p; i++)//全部进行检查
	{
		if (finish[i])continue;
		else
		{
			int temp[r];
			for (int j = 0; j < r; j++)temp[j] = need[i][j];
			if (com(ava, temp))
			{
				finish[i] = 1;
				cout << "第" << i + 1 << "个进程安全" << endl;
				for (int l = 0; l < r; l++)ava[l] += allo[i][l];
			}
		}
	}
	cout << endl;
	for (int i = 0; i < p; i++)
	{
		if (!finish[i])
		{
			cout << "第" << i + 1 << "个进程不安全!" << endl;
			return false;
		}
	}
	return true;
}

/*申请资源函数*/
void Apply(int allo[p][r], int need[p][r], int ava[r], int req[r], int n)
{
	n = n - 1;
	int temp[r];
	for (int i = 0; i < r; i++)temp[i] = need[n][i];
	if (!com(temp, req))
	{
		cout << "请求违法！" << endl;
		return;
	}
	else if (!com(ava, req))
	{
		cout << "发生阻塞" << endl;
		return;
	}
	else
	{
		for (int j = 0; j < r; j++)//试探性分配
		{
			allo[n][j] = allo[n][j] + req[j];
			need[n][j] = need[n][j] - req[j];
			ava[j] = ava[j] - req[j];
		}
		if (IsSafe(allo, need, ava))cout << "同意" << n + 1 << "个进程申请资源!" << endl;
		else
		{
			cout << "不同意" << n + 1 << "个进程申请资源!" << endl;
			cout << "恢复之前的状态!" << endl;
			for (int j = 0; j < r; j++)
			{
				allo[n][j] = allo[n][j] - req[j];
				need[n][j] = need[n][j] + req[j];
				ava[j] = ava[j] + req[j];
			}
		}
	}
}