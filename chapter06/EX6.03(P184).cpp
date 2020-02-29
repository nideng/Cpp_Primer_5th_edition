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
	cout << fact(3) << endl;
	return 0;
}