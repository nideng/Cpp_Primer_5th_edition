//for style
/*
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str("an example string");
	for (auto& s : str)
		s = 'X';
	cout << str << endl;
}
*/

//while style
#include<iostream>
#include<string>
using namespace std;
int main() {
	string str("an example string");
	decltype(str.size()) i = 0;
	while (i < str.size())
	{
		str[i] = 'X';
		++i;
	}
	cout << str << endl;
	return 0;
}