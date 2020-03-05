#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int>v1{ 0,1,2,3,4,5,6,7,8,9 };
	auto begin=v1.begin(),end=v1.end();
	while (begin != v1.end())
	{
			++begin;
		 v1.insert(begin, 42);//the code will crush,the iterator will be invalid
			++begin;
	}
	for (auto e : v1)
		cout << e << endl;
	return 0;
}