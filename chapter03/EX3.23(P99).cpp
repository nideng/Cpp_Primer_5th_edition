#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int>vec = { 1,2,3,4,5,6,7,8,9,10 };
	for (auto it = vec.begin(); it != vec.end(); ++it)
	{
		*it *=2;
		cout << *it << endl;
	}
	return 0;
}