#include<iostream>
#include<string>
using namespace std;
string& func(string& s, const string& s1, const string& s2)
{
	s.insert(0, s1);
	s.insert(s.size(), s2);
	return s;
}
int main()
{
	string s("neal");
	cout << func(s, "Mr.", "III") << endl;
	return 0;
}
