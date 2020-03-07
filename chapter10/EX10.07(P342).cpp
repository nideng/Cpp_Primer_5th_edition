#include<iostream>
#include<vector>
#include<list>
using namespace std;
int main()
{
	int i;
	vector<int>vec;
	list<int>lst;
	while (cin >> i)
		lst.push_back(i);
	//copy(lst.cbegin(), lst.cend(), vec.begin());
	copy(lst.cbegin(), lst.cend(), back_inserter(vec));
	for (auto e : vec)
		cout << e << endl;
	cout << "================================" << endl;
	vector<int>vec1;
	vec1.reserve(10);
	//fill_n(vec.begin(),10,0);
	fill_n(back_inserter(vec1), 10, 0);
	for (auto e : vec1)
		cout << e << endl;
	return 0;
}