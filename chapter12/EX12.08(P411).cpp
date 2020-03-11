#include<iostream>
using namespace std;
bool b()
{
	int* p = new int;
	*p = 2;
	return p;
}

int main()
{
	auto i=b();
	cout << i << endl;
	return 0;
}
/*
The p will convert to a bool , which means that the dynamic
memory allocated has no chance to be freed. As a result,
memory leakage will occur.
*/