/*
(a) string
(b)long double
(c)invalid, f is valid only with floating point literals
(d)long double
*/
//(c)
#include<iostream>
using namespace std;
int main()
{
	auto i = 1024.f;
	return 0;
}