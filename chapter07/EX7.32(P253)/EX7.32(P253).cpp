#include<iostream>
#include"EX7.32(P253).h"
#include<vector>
using namespace std;
int main()
{
	Screen s1;
	Screen s2(5, 5);
	Screen s3(5, 5, 'X');
	Window_mgr mgr1({ s1,s2,s3 });
	mgr1.getElement(2).display(cout);
	mgr1.clear(2);
	cout << endl;
	mgr1.getElement(2).display(cout);
	return 0;
}