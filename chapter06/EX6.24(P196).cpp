/*
So we cannot pass an array by value, and when we pass an array to a function, 
we are actually passing a pointer to the array's first element.
In this question, const int ia[10] is actually same as const int*, 
and the size of the array is irrelevant. we can pass const int ia[3] 
or const int ia[255], there are no differences. 
If we want to pass an array which size is ten, we should use reference like that:
*/

#include<iostream>
using namespace std;

void print(const int (&ia)[10])
{
	for (size_t i = 0; i != 10; ++i)
		cout << ia[i] << endl;
}

int main()
{
	int ia[10] ={ 1,2,3,4,5,6,7,8 };
	print(ia);
}