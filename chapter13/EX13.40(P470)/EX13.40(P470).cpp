#include"EX13.40(P470).h"
#include<iostream>
using namespace std;
int main()
{
	StrVec vec{ "hello","world" };
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