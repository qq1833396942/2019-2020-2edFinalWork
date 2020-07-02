#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class Student {
private:
	string m_name, m_id;
	int m_math, m_eng, m_phy, m_sum;
public:
	Student() {};
	Student(string i, string n, int m, int e, int p);
	~Student() {};
	int Sum();
	string GetName();
	string GetId();
	int GetMath();
	int GetEng();
	int GetPhy();
	void Show();
	Student& operator=(const Student& s);
};
#endif 
