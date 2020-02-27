//input a line at a time
/*
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	while (getline(cin, str))
		cout << str << endl;
	return 0;
}
*/
//input a word at a time
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	while (cin >> str)
		cout << str << endl;
	return 0;
}