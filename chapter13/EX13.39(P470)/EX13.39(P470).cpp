#include"EX13.39(P470).h"
#include<iostream>
using namespace std;
int main()
{
	StrVec vec;
	string s1("hello");
	string s2("world");
	vec.push_back(s1);
	vec.push_back(s2);
	for (auto e : vec)
		cout << e << endl;
	cout << vec.size() << endl;
	cout << vec.capacity() << endl;
	vec.reserve(10);
	cout << vec.capacity() << endl;
	vec.resize(3, "neal");
	cout << vec.size() << endl;
	for (auto e : vec)
		cout << e << endl;
}