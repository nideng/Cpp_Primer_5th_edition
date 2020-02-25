#include<iostream>
using namespace std;
int main()
{
	unsigned u = 10, u2 = 42;
	cout << u2 - u << endl;//result:32,unsigned int
	cout << u - u2 << endl;//result:a big number based on the type of system,unsigned int
	int i = 10, i2 = 42;
	cout << i2 - i << endl;//result:32,int
	cout << i - i2 << endl;//result:-32,int
	cout << i - u << endl;//result:0,unsigned int
	cout << u - i << endl;//result:0,unsigned int
	return 0;
}
