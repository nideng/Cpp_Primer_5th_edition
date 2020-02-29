#include<iostream>
using namespace std;

int compare_value(int i, const int* j)
{
	return (i > * j) ? i : (*j);
}

int main()
{
	int i = 1;
	const int* j = &i;
	cout << compare_value(2, j) << endl;
	return 0;
}