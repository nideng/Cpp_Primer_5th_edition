#include<iostream>
using namespace std;
int main()
{
	int j = 3, i = 2;
	double slope = static_cast<double>(j / i);//j/i is an int(by truncation), then converted to double and assigned to slope.
	double slope1 = static_cast<double>(j) / i;
	cout << slope << endl;
	cout << slope1 << endl;
	return 0;
}