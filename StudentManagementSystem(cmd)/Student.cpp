#include"student.h"
Student::Student(string i, string n, int m, int e, int p) {
	m_id = i;
	m_name = n;
	m_math = m;
	m_eng = e;
	m_phy = p;
	m_sum = m_math + m_eng + m_phy;
}
int Student::Sum() {
	m_sum = m_math + m_eng + m_phy;
	return m_sum;
}
string Student::GetName() {
	return m_name;
}
string Student::GetId() {
	return m_id;
}
int Student::GetMath() {
	return m_math;
}
int Student::GetEng() {
	return m_eng;
}
int Student::GetPhy() {
	return m_phy;
}
void Student::Show() {
	cout << m_id << '\t' << m_name << '\t' << m_math << '\t' << m_eng << '\t' << m_phy << '\t' << m_sum << endl;
}
Student& Student::operator=(const Student& s) {
	m_id = s.m_id;
	m_name = s.m_name;
	m_math = s.m_math;
	m_eng = s.m_eng;
	m_phy = s.m_phy;
	return *this;
}



