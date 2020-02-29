#include<iostream>
using namespace std;
void swap_pointer(int* &p1, int* &p2)//the reference is needed
{
	int* temp;
	temp = p1;
	p1 = p2;
	p2 = temp;
}

int main()
{
	int i = 1, j = 2;
	int* p1 = &i, * p2 = &j;
	cout << p1 << '\t' << p2 << endl;
	cout << *p1 << '\t' << *p2 << endl;
	swap_pointer(p1, p2);
	cout << p1 << '\t' << p2 << endl;
	cout << *p1 << '\t' << *p2 << endl;
	return 0;
}