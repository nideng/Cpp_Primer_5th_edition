#include<iostream>
#include<vector>
#include<list>
#include<iterator>
using namespace std;
int main()
{
	vector<int>vec1{ 1,2,3,4,5,6,7,8,9 };
	list<int>l1, l2, l3;
	copy(vec1.cbegin(), vec1.cend(), front_inserter(l1));
	copy(vec1.cbegin(), vec1.cend(), back_inserter(l2));
	copy(vec1.cbegin(), vec1.cend(), inserter(l3,l3.begin()));
	cout << "front_inserter" << '\t' << "back_inserter" << '\t' << "inserter" << endl;
	auto it1 = l1.begin();
	auto it2 = l2.begin();
	auto it3 = l3.begin();
	for (; it1 != l1.end(), it2 != l2.end(), it3 != l3.end(); ++it1, ++it2, ++it3)
		cout << *it1 << '\t' << *it2 << '\t' << *it3 << endl;
	return 0;
}