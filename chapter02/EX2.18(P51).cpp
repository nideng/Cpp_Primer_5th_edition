#include<iostream>
using namespace std;
int main()
{
	int i = 0;
	int* p = &i;
	cout << p << '\t' << *p << endl;
	int j = 0;
	p = &j;
	cout << p << '\t' << *p << endl;
	*p = 1;
	cout << p << '\t' << *p << endl;
	return 0;
}