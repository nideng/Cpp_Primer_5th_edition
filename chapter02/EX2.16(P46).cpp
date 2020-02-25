#include<iostream>
using namespace std;
int main()
{
	int i = 0, & r1 = i;
	double d = 0, & r2 = d;
	r2 = 3.1415926;
	cout << i << '\t' << r1 << '\t' << d << '\t' << r2 << endl;
	r2 = r1;
	cout << i << '\t' << r1 << '\t' << d << '\t' << r2 << endl;
	i = r2;
	cout << i << '\t' << r1 << '\t' << d << '\t' << r2 << endl;
	r1 = d;
	cout << i << '\t' << r1 << '\t' << d << '\t' << r2 << endl;
}

//all are valid;