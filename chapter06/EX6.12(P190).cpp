#include<iostream>
using namespace std;

void swap_value(int &p1, int &p2)
{
	int temp;
	temp = p1;
	p1 = p2;
	p2 = temp;
}
int main()
{
	int i = 1, j = 2;
	swap_value(i, j);
	cout << i << '\t' << j << endl;
	return 0;
}

//using reference is easier and terse;