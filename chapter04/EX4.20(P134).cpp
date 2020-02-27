/*
*iter++;  // return *iter, then ++iter.
(*iter)++;  // illegal, *iter is a string, cannot increment value.
*iter.empty() // illegal, iter should use '->' to indicate whether empty.
iter->empty();  // indicate the iter' value whether empty.
++*iter;        // illegal, string have not increment.
iter++->empty();  // return iter->empty(), then ++iter.

*/

//test for int 
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int>ia = { 0,2 };
	auto p = ia.begin();
	cout << (++*p) << endl;
	cout << (*++p) << endl;
	return 0;
}