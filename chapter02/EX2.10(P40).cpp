#include<iostream>
#include<string>
using namespace std;
string global_str;
int global_int;
int main()
{
	int local_int;
	string local_str;
	cout << global_str << endl;
	cout << global_int << endl;
	//cout << local_int << endl;
	cout << local_str << endl;
}
/*
global_str is global variable, so the value is empty string. global_int is global variable, 
so the value is zero. local_int is a local variable which is uninitialized, so it has a undefined value.
local_str is also a local variable which is uninitialized, but it has a value that is defined by the class.
So it is empty string. 
*/