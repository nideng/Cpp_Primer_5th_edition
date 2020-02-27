#include<iostream>
using namespace std;
int main()
{
	int array[10];
	for (size_t i = 0; i < 10; ++i)
	{
		array[i] = i;
		cout << array[i] << endl;
	}
	return 0;
}