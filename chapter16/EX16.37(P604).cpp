#include<iostream>
#include<algorithm>
using std::max;
int main()
{
	int i = 5; double j = 2.0;
	//Normal conversions also apply for arguments whose template type parameter is explicitly specified.
	std::cout << max<double>(i, j) << std::endl;
}