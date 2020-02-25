#include<iostream>
using namespace std;
int main()
{
	int i = 0, & r = i;
	const int ci = 1, & cr = ci;
	auto a = r;
	auto b = ci;
	auto c = cr;
	auto d = &i;
	auto e = &ci;
	auto& g = ci;
	a = 42;
	b = 42;
	c = 42;
	//d = 42;
	//e = 42;
	//g = 42;
	return 0;
}
//a = 42; set 42 to int a.
//b = 42; set 42 to int b.
//c = 42; set 42 to int c.
//d = 42; ERROR, d is an int *. correct: *d = 42;
//e = 42; ERROR, e is an const int *. correct: e = &c;
//g = 42; ERROR, g is a const int& that is bound to ci.