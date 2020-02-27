#include<iostream>
#include<string>
using namespace std;


int main()
{
	string str1("Neal Ni"), str2("Neal ni");
	if (str1 == str2)
		cout << "two strings are equal" << endl;
	else if (str1 > str2)
		cout << str1 << ">" << str2 << endl;
	else
		cout << str1 << "<" << str2 << endl;
	cout << "=============================" << endl;
	const char ch1[] = "Neal Ni", ch2[] = "Neal ni";
	if (strcmp(ch1, ch2) > 0)
		cout << ch1 << ">" << ch2 << endl;
	else if (strcmp(ch1, ch2) == 0)
		cout << "Two strings are equal" << endl;
	else
		cout << ch1 << "<" << ch2 << endl;
	return 0;

}