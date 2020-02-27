/*
(a) check ptr is not a nullptr, and then check the pointer value.
(b) check ival, and then check ival+1 whether equal zero.
(c) incorrect. It is an **undefined behavior.**

*/


#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int ival = 0;
	int* ptr = &ival;
	bool k = (ptr != 0 && *ptr++);
	cout << *ptr << endl;
	cout << k << endl;
	cout << "==========================" << endl;
	bool l = ival++ && 1;
	cout << l << endl;
	cout << "==============================" << endl;
	vector<int>vec{ 2,0 };
	ival = 0;
	bool m = (vec[ival++] < vec[ival]);

}