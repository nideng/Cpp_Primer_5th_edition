#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s1, s2;
	cout << "Enter two strings: " << endl;
	cin >> s1 >> s2;
	do
	{
		if (s1.size() == s2.size())
			cout << "The two strings are equal. " << endl;
		else
			cout << "The shorter string is: " << ((s1.size() < s2.size()) ? s1 : s2) << endl;
	} while (cin >> s1 >> s2);
	return 0;
}