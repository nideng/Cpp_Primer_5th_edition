/*
i*=static_cast<int>(d)
*/

#include<iostream>
using namespace std;

int main()
{
	int i = 1;
	double d = 2.3;
	i *= static_cast<int>(d);
	cout << i << endl;
	return 0;
}