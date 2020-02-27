#include<iostream>
using namespace std;
int main()
{
	int a,b, c, d;
	while (cin >> a >> b >> c >> d)
	{
		if (a > b&& b > c&& c > d)
			continue;
		break;
	}
	return 0;
}