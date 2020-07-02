#pragma once
#ifndef MANAGE_H
#define MANAGE_H
#include"student.h"
#include<iostream>
#include<cmath>
#include<fstream>
#include<ostream>
#include<vector>
using namespace std;
class Manage {
private:
	vector<Student>stu;
public:
	void AddRecord();
	void Analyse();
	void OutFile();
	void DeleRecord();
	void ChangeRecord();
	int SearchId();
	int SearchName();
	void SearchScore();
	void Average();
	void Standard();
	void Pass();
	void Sort();
	void InFile();
	int Search();
	void Display();
};
#endif
