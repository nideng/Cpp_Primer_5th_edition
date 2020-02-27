#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int>vec{ 0,1,2,3,4 };
	int arr[5];
	for (int i = 0; i < 5; i++)
	{
		arr[i] = vec[i];
		cout << arr[i] << endl;
	}
	return 0;
}