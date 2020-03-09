#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main()
{
	map<string, vector<string>>family;
	string last_name,child_name;
	cout << "Input the last name of families('q' to quit): " << endl;
	while (cin >> last_name&&last_name!="q")
	{
		cout << "Input the child name('q' to quit): " << endl;
		while (cin >> child_name&&child_name!="q")
			family[last_name].push_back(child_name);
		cout << "Input the last name of families('q' to quit): " << endl;
	}
	for (const auto& fam : family)
	{
		cout << "last name of family :" << fam.first << endl;
		cout << "child name:" << endl;
		for (const auto& chi : fam.second)
			cout << chi << '\t';
		cout << endl;
	}
	return 0;
}