#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<iostream>
#include<string>
using namespace std;
class Employee
{
public:
	Employee() :Employee_number(num) { num++; }
	Employee(const string& s) :Employee_name(s), Employee_number(num) { ++num; }
	void print() { cout << "Name: " << Employee_name << endl; cout << "Number: " << Employee_number << endl; }
private:
	string Employee_name;
	unsigned Employee_number;
	static unsigned num;
};
unsigned Employee::num = 0;
#endif // !EMPLOYEE_H