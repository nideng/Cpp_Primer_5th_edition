#include<vector>
#include<list>
#include<iostream>
#include<iterator>
using namespace std;
int main()
{
	int ia[] = { 0,1,1,2,3,5,8,13,21,55,89 };
	vector<int>vec(begin(ia),end(ia));
	list<int>l1(begin(ia), end(ia));
	auto it1 = l1.begin();
	auto it2 = vec.begin();
	while (it1 != l1.end())
		if (*it1 % 2)
			it1 = l1.erase(it1);
		else
			++it1;
	while (it2 != vec.end())
		if (!(*it2 % 2))
			it2 = vec.erase(it2);
		else ++it2;
	for (auto e : l1)
		cout << e << endl;
	cout << "==================" << endl;
	for (auto e : vec)
		cout << e << endl;
	return 0;
}