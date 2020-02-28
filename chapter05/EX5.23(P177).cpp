#include<iostream>
#include<stdexcept>
using namespace std;
runtime_error err("The second number should not be zero!");
int main()
{
	int i, j;
	while (cin >> i >> j)
	{
		cout << i / j << endl;
	}
	return 0;
}
