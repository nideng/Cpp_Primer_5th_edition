#include<iostream>
#include<string>
using namespace std;

void func(string& s, const string& oldVal,const string& newVal)
{
	for (auto it = s.begin(); it != (s.end()-oldVal.size());++it)//(s.end()-oldVal.size()) is necessary
	{
		if (oldVal == string(it, it + oldVal.size()))
		{
			it = s.erase(it, it + oldVal.size());
			it=s.insert(it,newVal.begin(),newVal.end());
			it +=( newVal.size()-1);
		}
	}
}
int main()
{
	string s("hellotho thruworld" );
	func(s, "tho", "though");
	func(s, "thru", "through");
	cout << s;
	return 0;
}