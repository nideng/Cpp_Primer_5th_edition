#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
bool string_size(const string& s)
{
	return (s.size() > 4);
}
int main()
{
	vector<string>vec{ "neal","hello","world","ni","C++ Primer" };
	auto it=partition(vec.begin(), vec.end(), string_size);
	for(auto i=vec.begin();i!=it;++i)
	cout << *i << endl;
	return 0;
}