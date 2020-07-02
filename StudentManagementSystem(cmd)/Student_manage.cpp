#include"manage.h"
#include<iostream>
using namespace std;
int main() {
	int l, g;
	Manage ma;
	cout << endl;
	cout << "********************************学生成绩管理系统********************************" << endl;
	ma.InFile();
	do {
		cout << "                              ·输入您选择的序号·                              " << endl;
		cout << "1、增加学生记录" <<
			endl << "2、删减学生记录" <<
			endl << "3、成绩修改    " <<
			endl << "4、个人成绩查看    " <<
			endl << "5、总体成绩分析    " << endl;

		do {
			cin >> l;
			switch (l) {
			case 1:
				ma.AddRecord(); break;
			case 2:
				ma.DeleRecord(); break;
			case 3:
				ma.ChangeRecord(); break;
			case 4:
				ma.Search(); break;
			case 5:
				ma.Analyse(); break;
			default:cout << "输入错误请重新输入" << endl; break;
			}
		} while (l != 1 && l != 2 && l != 3 && l != 4 && l != 5);
		cout << "1.继续进行成绩管理" << endl;
		cout << "2.退出管理系统" << endl;
		cin >> g;
	} while (g == 1);
	cout << "                            感谢使用本系统！" << endl;
	return 0;
}