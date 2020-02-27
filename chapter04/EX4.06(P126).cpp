
#include<iostream>
using namespace std;
int main()
{
	int i;
	while (cin >> i)
		cout << (i &1 ) << endl;//result 1:odd; result 0:even
	return 0;
}