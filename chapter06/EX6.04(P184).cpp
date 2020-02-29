#include<iostream>
using namespace std;
unsigned fact(unsigned val)
{
	if (val > 1)
		return  val * fact(val - 1);
	else
		return 1;
}
int main()
{
	unsigned i;
	cout << "Enter an unsigned int number: ";
	cin >> i;
	cout << "The factorial of " << i << " is: ";
	cout << fact(i) << endl;
	return 0;
}