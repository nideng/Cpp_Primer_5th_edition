#include<iostream>
using std::cout;
using std::cin;
using std::endl;
void print_number(int i, int j)
{
	if (i > j)
		print_number(j, i);
	while (i <= j)
	{
		cout << i << endl;
		++i;
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