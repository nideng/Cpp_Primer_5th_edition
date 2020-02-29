#include<iostream>
#include<vector>
using namespace std;
using it = vector<int>::iterator;

void value(it it1,it it2)
{
	if (it1 != it2)
	{
		cout << *it1 << endl;
		value(++it1,it2);
	}
}

int main()
{
	vector<int>vec1{ 2,1,3,4,5,6 };
	value(vec1.begin(), vec1.end());
}