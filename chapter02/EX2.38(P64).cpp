/*
The way decltype handles top - level constand references differs subtly from the way auto does.
Another important difference between decltype and auto is that the deduction done by decltype depends on 
the form of its given expression.
so the key of difference is subtly and form.
*/
#include<iostream>
using namespace std;
int main()
{
	int i = 0, & r = i;
	// same
	auto a = i;
	decltype(i) b = i;
	// different "c" will be int "d" will be int&
	auto c = r;
	decltype(r) d = r;
	return 0;
}