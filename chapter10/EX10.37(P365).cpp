#include<iostream>
#include<vector>
#include<list>
#include<iterator>
using namespace std;

int main()
{
	vector<int>vec{ 0,1,2,3,4,5,6,7,8,9 };
	list<int>l1(vec.crbegin() + 3, vec.crbegin() +8);
	for (auto e : l1)
		cout << e << endl;
	return 0;
}
