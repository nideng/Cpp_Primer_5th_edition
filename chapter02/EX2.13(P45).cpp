/*
j=100, the local i hidden the global i
*/
#include<iostream>
using namespace std;
int i = 42;
int main()
{
	int i = 100;
	int j = i;
	cout << j << endl;
	return 0;
}