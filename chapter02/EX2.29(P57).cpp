/*
(a) legal.
(b£©illegal. p3 is a const pointer to const int.
(c) illegal. ic is a const int.
(d) legal
(e) legal.
(f) illegal. ic is a const int
*/

#include<iostream>
using namespace std;
int main()
{
	int i = 1;
	const int ic = 2;
	i = ic;
	const int* const p3 = &ic;
	int j = 1;
	int* p1 = &j;
	//p1 = p3;
	//p1 = &ic;
	int* const p2 = p1;
	cout << p2 << " " << p1 << endl;
	int k = 2;
	p1 = &k;
	cout << p2 << " " << p1 << endl;
	//ic = *p3;
	return 0;
}