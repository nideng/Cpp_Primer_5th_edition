#include<iostream>
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
	istream& is = func(cin);
	cout << is.rdstate() << endl;
	return 0;
}