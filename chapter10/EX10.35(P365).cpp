#include<iostream>
#include<vector>
#include<iterator>
using namespace std;
int main()
{
	
	vector<int>vec{ 0,1,2,3,4,5,6,7,8,9,10 };

	for (auto it = vec.cend() - 1; it != vec.begin(); --it)//or: auto it=prev(vec.end())
		cout << *it << endl;
	cout << *vec.cbegin();
	return 0;
}