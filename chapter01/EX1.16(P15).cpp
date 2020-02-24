#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int sum = 0, val;
	while (cin >> val)
	{
		sum += val;
		cout << sum << endl;
	}
/*
//forÑùÊ½
	for (int i, sum = 0; cin >> i; sum += i)
		cout << sum << endl;
*/
	return 0;
}