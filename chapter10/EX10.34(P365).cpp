#include<iostream>
#include<vector>
#include<iterator>
using namespace std;
int main()
{
	vector<int>vec{ 0,1,2,3,4,5,6,7,8,9,10 };
	for (auto it = vec.crbegin(); it != vec.crend(); ++it)
		cout << *it << endl;
	return 0;
}