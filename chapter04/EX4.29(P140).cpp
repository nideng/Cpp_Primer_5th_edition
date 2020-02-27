//10 ,1 
//p is a pointer to the first element in array,sizeof(p) equal to sizeof(int)
#include<iostream>
using namespace std;
int main()
{
	int x[10];
	int* p = x;
	cout << sizeof(x) / sizeof(*x) << endl;
	cout << sizeof(p) / sizeof(*p) << endl;
}