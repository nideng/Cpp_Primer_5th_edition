#include<iostream>
using namespace std;

double abs_value(double val)
{
	return (val >= 0) ?  val : -val;
}

int main()
{
	double i;
	cout << "Enter a double type number: ";
	cin >> i;
	cout << "The absolute value is: " << abs_value(i) << endl;
	return 0;
}