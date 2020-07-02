#include"manage.h"
#include<conio.h>

int m, e, p;
string i, n;
//---------------------------------------------------增加成绩
void Manage::AddRecord() {
	int k(0), t;
	do {
		do {
			cout << "---------------------------------------------------" << endl;
			cout << "请按顺序输入学生的学号 姓名 数学 英语 物理：" << endl;
			cin >> i >> n >> m >> e >> p;
			for (t = 0; t < stu.size(); t++) {
				if (i == stu[t].GetId() || n == stu[t].GetName()) {
					cout << "已有该生成绩！" << endl;
					k = 1;
				}
			}
			if (m > 100 || m < 0 || e>100 || e < 0 || p>100 || p < 0) {
				cout << "输入成绩范围为0-100" << endl;
				k = 1;
			}
		} while (k == 1);
		Student s(i, n, m, e, p);
		s.Show();
		cout << "---------------------------------------------------" << endl;
		cout << "是否保存:" << endl << "1.是  2.否" << endl;
		cin >> k;
		if (k == 1) {
			stu.push_back(s);
			OutFile();
		}
		cout << "---------------------------------------------------" << endl;
		cout << "是否继续添加" << endl;
		cout << "1.是 2.否" << endl;
		cin >> k;
	} while (k == 1);
}
//---------------------------------------------------查找成绩
int Manage::Search() {
	int k, t;
	do {
		cout << "请选择查找方式：" << endl;
		cout << "-----------------------------------------------------------" << endl;
		cout << "1.学号" << '\t' << '\t' << "2.姓名" << endl;
		cin >> k;//或者用switch语句？
		if (k == 1) t = SearchId();
		else if (k == 2) t = SearchName();
		else cout << "输入错误!!" << endl;
		cout << "-----------------------------------------------------------" << endl;
		cout << "是否重新查找?" << endl;
		do {
			cout << "1.是" << '\t' << '\t' << "2.否" << endl;
			cin >> k;
		} while (k != 1 && k != 2);
	} while (k == 1);
	return t;
	//http://www.todo.net.cn/tech/article.asp?id=530 vector迭代器插入删除
}
//----------------------------------------------------学号查找
int Manage::SearchId() {
	int t;
	string id;
	do {
		cout << "输入正确的学号：" << endl;
		cin >> id;
		for (t = 0; t < stu.size(); ) {
			if (id == stu[t].GetId())  break;
			else t++;
		}
	} while (t == stu.size());//problem  t++
	cout << "学号" << '\t' << '\t' << "姓名" << '\t' << "数学" << '\t' << "英语" << '\t' << "物理" << endl;
	stu[t].Show();
	return t;
}
//----------------------------------------------------姓名查找
int Manage::SearchName() {
	string name;
	int t;
	do {

		cout << "输入正确的姓名：" << endl;
		cin >> name;
		for (t = 0; t < stu.size();) {
			if (name == stu[t].GetName()) break;
			else t++;
		}
	} while (t == stu.size());
	cout << "学号" << '\t' << '\t' << "姓名" << '\t' << "数学" << '\t' << "英语" << '\t' << "物理" << endl;
	stu[t].Show();
	return t;
}
//----------------------------------------------------分数段查找
void Manage::SearchScore() {
	int k, max, min, t, temp;
	do {
		do {
			cout << "输入查找科目:" << endl;
			cout << "-----------------------------------------------------------" << endl;
			cout << "1.数学" << '\t' << '\t' << "2.英语" << '\t' << '\t' << "3.物理" << endl;
			cin >> k;
			if (k != 1 && k != 2 && k != 3) {
				cout << "输入错误！请重新输入！" << endl;
			}
		} while (k != 1 && k != 2 && k != 3);

		cout << "输入查找上限和下限:" << endl;
		do {
			cin >> max >> min;
			if (max < min || max>100 || min < 0)cout << "输入错误！请重新输入:" << endl;
		} while (max < min || max>100 || min < 0);
		cout << "-----------------------------------------------------------" << endl;
		cout << "查询结果为:" << endl;
		switch (k) {
		case 1:
			for (t = 0; t < stu.size(); t++) {
				temp = stu[t].GetMath();
				if (temp <= max && temp >= min)
					stu[t].Show();
			};
			break;
		case 2:
			for (t = 0; t < stu.size(); t++) {
				temp = stu[t].GetEng();
				if (temp <= max && temp >= min)
					stu[t].Show();
			};
			break;
		case 3:
			for (t = 0; t < stu.size(); t++) {
				temp = stu[t].GetPhy();
				if (temp <= max && temp >= min)
					stu[t].Show();
			};
			break;
		default:cout << "输入错误!!" << endl; break;
		}
		cout << "-----------------------------------------------------------" << endl;
		cout << "是否继续按分数段查询" << endl;
		cout << "1.是 2.否" << endl;
		cin >> k;
	} while (k == 1);
}
//----------------------------------------------------求平均值
void Manage::Average() {
	int t, k;
	double average, add(0);
	do {
		cout << "输入需求平均值的科目:" << endl;
		cout << "-----------------------------------------------------------" << endl;
		do {
			cout << "1.数学" << '\t' << "2.英语" << '\t' << "3.物理" << '\t' << "4.总分" << endl;
			cin >> k;
			if (k != 1 && k != 2 && k != 3 && k != 4) {
				cout << "输入错误！请重新输入！" << endl;
			}
		} while (k != 1 && k != 2 && k != 3 && k != 4);
		switch (k) {
		case 1:
			for (t = 0; t < stu.size(); t++) {
				add += stu[t].GetMath();
			}
			average = add / stu.size();
			cout << "数学的平均分是：" << average << endl;
			break;
		case 2:
			for (t = 0; t < stu.size(); t++) {
				add += stu[t].GetEng();
			}
			average = add / stu.size();
			cout << "英语的平均分是：" << average << endl;
			break;
		case 3:
			for (t = 0; t < stu.size(); t++) {
				add += stu[t].GetPhy();
			}
			average = add / stu.size();
			cout << "物理的平均分是：" << average << endl;
			break;
		case 4:
			for (t = 0; t < stu.size(); t++) {
				add += stu[t].Sum();
			}
			average = add / stu.size();
			cout << "总分的平均分是：" << average << endl;
			break;
		}
		cout << "-----------------------------------------------------------" << endl;
		cout << "是否继续求平均值？" << endl;
		cout << "1.是   2.否" << endl;
		cin >> k;
	} while (k == 1);
}
//------------------------------------------------------------求标准差
void Manage::Standard() {
	int t, k;
	double standardadd(0), standard, add(0), average;
	do {
		cout << "输入需求标准差的科目:" << endl;
		cout << "-----------------------------------------------------------" << endl;
		do {
			cout << "1.数学" << '\t' << "2.英语" << '\t' << "3.物理" << '\t' << "4.总分" << endl;
			cin >> k;
			if (k != 1 && k != 2 && k != 3 && k != 4) {
				cout << "输入错误！请重新输入！" << endl;
			}
		} while (k != 1 && k != 2 && k != 3 && k != 4);
		switch (k) {
		case 1:
			for (t = 0; t < stu.size(); t++) {
				add += stu[t].GetMath();
			}
			average = add / stu.size();
			for (t = 0; t < stu.size(); t++) {
				standardadd += (stu[t].GetMath() - average) * (stu[t].GetMath() - average);
			}
			standard = sqrt(standardadd / stu.size());
			cout << "数学的标准差是：" << standard << endl;
			break;
		case 2:
			for (t = 0; t < stu.size(); t++) {
				add += stu[t].GetEng();
			}
			average = add / stu.size();
			for (t = 0; t < stu.size(); t++) {
				standardadd += (stu[t].GetEng() - average) * (stu[t].GetEng() - average);
			}
			standard = sqrt(standardadd / stu.size());
			cout << "英语的标准差是：" << standard << endl;
			break;
		case 3:
			for (t = 0; t < stu.size(); t++) {
				add += stu[t].GetPhy();
			}
			average = add / stu.size();
			for (t = 0; t < stu.size(); t++) {
				standardadd += (stu[t].GetPhy() - average) * (stu[t].GetPhy() - average);
			}
			standard = sqrt(standardadd / stu.size());
			cout << "物理的标准差是：" << standard << endl;
			break;
		case 4:
			for (t = 0; t < stu.size(); t++) {
				add += stu[t].Sum();
			}
			average = add / stu.size();
			for (t = 0; t < stu.size(); t++) {
				standardadd += (stu[t].Sum() - average) * (stu[t].Sum() - average);
			}
			standard = sqrt(standardadd / stu.size());
			cout << "总分的标准差是：" << standard << endl;
			break;
		default:
			cout << "输入错误" << endl;
			break;
		}
		cout << "-----------------------------------------------------------" << endl;
		cout << "是否继续求标准差？" << endl;
		cout << "1.是   2.否" << endl;
		cin >> k;
	} while (k == 1);
}
//------------------------------------------------------------------------------------求及格率
void Manage::Pass() {
	int k, t;
	int temp;
	double pass, pa(0);
	do {
		cout << "输入需求及格率的科目:" << endl;
		cout << "-----------------------------------------------------------" << endl;
		do {
			cout << "1.数学" << '\t' << '\t' << "2.英语" << '\t' << '\t' << "3.物理" << endl;
			cin >> k;
			if (k != 1 && k != 2 && k != 3) {
				cout << "输入错误！请重新输入！" << endl;
			}
		} while (k != 1 && k != 2 && k != 3);
		switch (k) {
		case 1:
			for (t = 0; t < stu.size(); t++) {
				temp = stu[t].GetMath();
				if (temp >= 60) pa++;
			}
			pass = pa / stu.size();
			cout << "数学的及格率是：" << pass << endl;
			pa = 0;
			break;
		case 2:
			for (t = 0; t < stu.size(); t++) {
				temp = stu[t].GetEng();
				if (temp >= 60) pa++;
			}
			pass = pa / stu.size();
			cout << "英语的及格率是：" << pass << endl;
			pa = 0;
			break;
		case 3:
			for (t = 0; t < stu.size(); t++) {
				temp = stu[t].GetPhy();
				if (temp >= 60) pa++;
			}
			pass = pa / stu.size();
			cout << "物理的及格率是：" << pass << endl;
			pa = 0;
			break;
		default:cout << "输入错误！！" << endl;
		}
		cout << "-----------------------------------------------------------" << endl;
		cout << "是否继续求及格率？" << endl;
		cout << "1.是   2.否" << endl;
		cin >> k;
	} while (k == 1);
}
//--------------------------------------------------------------------------文件输入
void Manage::InFile() {
	int t, k;
	ifstream ifile;
	ifile.open("D:/data.txt");
	if (!ifile) cout << "Error!" << endl;
	do {
		ifile >> i >> n >> m >> e >> p;
		Student s(i, n, m, e, p);
		stu.push_back(s);
	} while (!ifile.eof());
}
//---------------------------------------------------------------------------成绩分析选项
void Manage::Analyse() {
	int k;
	do {
		cout << "                              ·输入您选择的序号·                              " << endl;
		cout << "1.显示全班成绩" << endl;
		cout << "2.平均分" << endl;
		cout << "3.合格率" << endl;
		cout << "4.标准差" << endl;
		cout << "5.查看处于某分数段的同学" << endl;
		cout << "6.对成绩进行排序" << endl;
		cin >> k;
		switch (k) {
		case 1:Display(); break;
		case 2:Average(); break;
		case 3:Pass(); break;
		case 4:Standard(); break;
		case 5:SearchScore(); break;
		case 6:Sort(); break;
		default:cout << "输入错误" << endl; break;
		}
		cout << "-----------------------------------------------------------" << endl;
		cout << "1.继续进行总体成绩分析" << endl;
		cout << "2.返回上层" << endl;
		cin >> k;
	} while (k == 1);
}//-------------------------------------------------------------------------------------成绩排序
void Manage::Sort() {
	int q, p, k;
	for (q = 0; q < stu.size(); q++)
		for (p = 0; p < stu.size(); p++)
		{
			if (stu[q].Sum() > stu[p].Sum())			//先按照总成绩排序
			{
				Student s = stu[p];
				stu[p] = stu[q];
				stu[q] = s;
			}
		}

	for (q = 0; q < stu.size(); q++)
		for (p = 0; p < stu.size(); p++) {
			if (stu[q].Sum() == stu[p].Sum() && stu[q].GetMath() > stu[p].GetMath())	//总成绩相同按照数学成绩排
			{
				Student s = stu[p];
				stu[p] = stu[q];
				stu[q] = s;
			}
		}
	for (q = 0; q < stu.size(); q++)
		for (p = 0; p < stu.size(); p++) {
			if (stu[q].Sum() == stu[p].Sum() && stu[q].GetMath() == stu[p].GetMath() && stu[q].GetPhy() > stu[p].GetPhy())	//数学成绩也相同，按物理成绩排
			{
				Student s = stu[p];
				stu[p] = stu[q];
				stu[q] = s;
			}
		}
	for (q = 0; q < stu.size(); q++)
		for (p = 0; p < stu.size(); p++) {
			if (stu[q].Sum() == stu[p].Sum() && stu[q].GetMath() == stu[p].GetMath() && stu[q].GetPhy() == stu[p].GetPhy() && stu[q].GetEng() > stu[p].GetEng())	//若物理成绩也相同，则按英语成绩排
			{
				Student s = stu[p];
				stu[p] = stu[q];
				stu[q] = s;
			}
		}
	for (q = 0; q < stu.size(); q++)
		for (p = 0; p < stu.size(); p++) {
			if (stu[q].Sum() == stu[p].Sum() && stu[q].GetMath() == stu[p].GetMath() && stu[q].GetPhy() == stu[p].GetPhy() && stu[q].GetEng() == stu[p].GetEng() && stu[q].GetId() > stu[p].GetId())		//若各科成绩都一样，则按学号排序
			{
				Student s = stu[p];
				stu[p] = stu[q];
				stu[q] = s;
			}
		}
	Display();
	cout << "-----------------------------------------------------------" << endl;
	cout << "是否将排序存入文本？" << endl;
	cout << "1.是     2.否" << endl;
	cin >> k;
	if (k == 1) OutFile();

}
//-----------------------------------------------------------------------------------------------------------------更改成绩
void Manage::ChangeRecord() {
	int t;
	t = Search();
	int k, temp;
	do {
		do {
			cout << "请选择修改项目" << endl;
			cout << "-----------------------------------------------------------" << endl;
			cout << "1.数学" << '\t' << '\t' << "2.英语" << '\t' << '\t' << "3.物理" << endl;
			cin >> k;
			if (k != 1 && k != 2 && k != 3) {
				cout << "输入错误！请重新输入！" << endl;
			}
		} while (k != 1 && k != 2 && k != 3);
		do {
			cout << "请输入修改值：" << endl;
			cin >> temp;
			if (temp > 100 || temp < 0) {
				cout << "输入值不合法!" << endl;
			}
		} while (temp > 100 || temp < 0);
		i = stu[t].GetId();
		n = stu[t].GetName();
		m = stu[t].GetMath();
		e = stu[t].GetEng();
		p = stu[t].GetPhy();
		switch (k) {
		case 1:
			m = temp; break;
		case 2:
			e = temp; break;
		case 3:
			p = temp; break;
		default:; break;
		}
		cout << "请确认是否修改？" << endl;
		cout << "1.是 2.否" << endl;
		cin >> k;
		if (k == 1) {
			Student s(i, n, m, e, p);
			stu[t] = s;
			OutFile();
		}
		else cout << "结果未保存" << endl;
		cout << "-----------------------------------------------------------" << endl;
		cout << "是否继续修改" << endl;
		cout << "1.是  2.否" << endl;
		cin >> k;
	} while (k == 1);
}
//---------------------------------------------------------------------------------------------文件输出
void Manage::OutFile() {
	int t;
	ofstream ofile;
	ofile.open("D:/data.txt");
	ofile << "学号" << '\t' << '\t' << "姓名" << '\t' << "数学" << '\t' << "英语" << '\t' << "物理" << endl;
	for (t = 0; t < stu.size(); t++) {
		ofile << stu[t].GetId() << '\t' << stu[t].GetName() << '\t' << stu[t].GetMath() << '\t' << stu[t].GetEng() << '\t' << stu[t].GetPhy() << endl;
	}
	ofile.close();
	cout << "保存成功！" << endl;
}
//-----------------------------------------------------------------------------------------------------删除记录
void Manage::DeleRecord() {
	int k, x, t;
	Student temp;
	do {
		t = Search();
		cout << "-----------------------------------------------------------" << endl;
		cout << "确认删除此记录？" << endl;
		cout << "1.是" << endl;
		cout << "2.否" << endl;
		cin >> k;
		if (k == 1) {
			for (x = t; x < stu.size() - 1; x++) {
				temp = stu[x];
				stu[x] = stu[x + 1];
				stu[x + 1] = temp;
			}
			stu.pop_back();
			cout << "删除成功!" << endl;
			OutFile();
		}
		cout << "-----------------------------------------------------------" << endl;
		cout << "是否继续删除？" << endl;
		cout << "1.是" << endl;
		cout << "2.否" << endl;
		cin >> k;
	} while (k == 1);
}
//-------------------------------------------------------------------------------------------------显示所有成绩
void Manage::Display() {
	int t;
	for (t = 0; t < stu.size(); t++) {
		stu[t].Show();
	}
}
