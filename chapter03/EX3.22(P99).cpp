
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	string str;
	vector<string>text;
	while (getline(cin, str))
		text.push_back(str);
	for (auto it = text.begin(); it != text.end(); ++it)
	{
		for (auto j = it->begin(); j != it->end(); ++j)
			if (isalpha(*j)) *j = toupper(*j);
		cout << *it << endl;
	}
	return 0;

}
