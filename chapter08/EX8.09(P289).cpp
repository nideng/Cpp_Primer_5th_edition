#include<iostream>
#include<sstream>
#include<string>
using namespace std;
istream& func(istream& is)
{
	string s;
	while (is >> s)
	{
		cout << s << endl;
	}
	is.clear();
	return is;
}
int main()
{
	istringstream iss;
	func(iss);
	istringstream iss2("hello world");
	func(iss2);
	return 0;
}