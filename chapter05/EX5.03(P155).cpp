/*
#include<iostream>
int main()
{
	int sum = 0;
	int val = 50;
	while (val <= 100)
		sum += val,++val;
	std::cout << "Sum of 50 to 100 is: " << sum << std::endl;
	return 0;
}
*/

/*
#include<iostream>

int main()
{
	int val = 10, sum = 0;
	while (val >= 0)
		sum += val,--val;
	std::cout << "Sum of 0 to 10 is: " << sum << std::endl;
	return 0;
}
*/


#include<iostream>
using std::cout;
using std::cin;
using std::endl;
void print_number(int i, int j)
{
	if (i > j)
		print_number(j, i);
	while (i <= j)
		cout << i << endl,++i;
}
int main()
{
	cout << "Enter two numbers(int): " << endl;
	int x, y;
	cin >> x >> y;
	cout << "The list of numbers between" << x << " and " << y << " is:" << endl;
	print_number(x, y);
	return 0;
}