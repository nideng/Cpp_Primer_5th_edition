//EX1.9
/*
#include<iostream>
int main()
{
	int sum = 0;
	for(int val=50;val <= 100;++val)
	{
		sum += val;
	}
	std::cout << "Sum of 50 to 100 is: " << sum << std::endl;
	return 0;
}
*/

//EX1.10
/*
#include<iostream>

int main()
{
	int sum = 0;
	for(int val=10;val>=0;--val)
	{
		sum += val;
	}
	std::cout << "Sum of 0 to 10 is: " << sum << std::endl;
	return 0;
}
*/

//EX1.11
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
void print_number(int i, int j)
{
	if (i > j)
		print_number(j, i);
	for(;i <= j;++i)
	{
		cout << i << endl;
	}
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
