#include<iostream>
#include<string>
using namespace std;

void func(string& s, const string& oldVal, const string& newVal)
{
	for (size_t it = 0; it != (s.size() - oldVal.size()); ++it)
	{
		if (oldVal == s.substr(it, oldVal.size()))
		{
			s.replace(it,oldVal.size(), newVal);
			it += (newVal.size() - 1);
		}
	}
}
int main()
{
	string s("hellotho thruworld");
	func(s, "tho", "though");
	func(s, "thru", "through");
	cout << s;
	return 0;
}