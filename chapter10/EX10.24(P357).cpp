#include<iostream>
#include<string>
#include<vector>
#include<functional>
using namespace std;
using namespace std::placeholders;

bool check_size(const string& s, string::size_type sz)
{
	return s.size() <sz;
}
int main()
{
	string s = "hello";
	vector<int>vec1 = { 1,2,3,4,5,1,2,6,3,5 };
	auto it=find_if(vec1.begin(), vec1.end(), bind(check_size, s, _1));
	if (it != vec1.end())
		cout << *it << endl;
	else
		cout << "Not found" << endl;
	return 0;
}