#include<iostream>
using namespace std;
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	for (auto i = arr; i != &arr[10]; ++i)
		*i = 0;
	for(auto e:arr)
		cout << e << endl;
	return 0;
}