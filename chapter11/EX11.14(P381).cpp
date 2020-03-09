#include<iostream>
#include<map>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	map<string, vector<pair<string,string>>>family;
	string last_name, child_name,child_birth;
	cout << "Input the last name of families('q' to quit): " << endl;
	while (cin >> last_name && last_name != "q")
	{
		cout << "Input the child name and child birth('q' to quit): " << endl;
		while (cin >> child_name >>child_birth&& child_name != "q")
			family[last_name].push_back({ child_name,child_birth });
		cout << "Input the last name of families('q' to quit): " << endl;
	}
	for (const auto& fam : family)
	{
		cout << "last name of family :" << fam.first << endl;
		cout << "child name:" << endl;
		for (const auto& chi : fam.second)
			cout << chi.first << '\t' << chi.second << endl;
		cout << endl;
	}
	return 0;
}