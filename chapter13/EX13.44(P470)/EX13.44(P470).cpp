#include"EX13.44(P470).h"
#include<iostream>
#include<string>
using namespace std;
int main()
{
	String s1;
	String s2("hello world");
	s1 = s2;
	cout << s2 << endl;
	cout << s1.size() << endl;
}