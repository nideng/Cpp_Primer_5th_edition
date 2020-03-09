/*
UB,since it's trying to dereference an item out of range.
*/
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int>v;
	v[0] = 1;
	cout << v[0] << endl;
	return 0;
}
