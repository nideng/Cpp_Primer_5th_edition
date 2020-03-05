#include<iostream>
#include<string>
using namespace std;

string& func(string& s, const string& s1, const string& s2)
{
	s.insert(s.begin(),s1.begin(),s1.end());
	return s.append(s2);
}
int main()
{
	string s("neal");
	cout << func(s, "Mr.", "III") << endl;
	return 0;
}