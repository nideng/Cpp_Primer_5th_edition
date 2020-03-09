#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;
int main()
{
	map<string, vector<int>>m1{ {"neal",{1,2,3}},{"ni",{2,3,4}},
	{"c++",{1,2}},{"neal",{1,3}},{"primer",{2,3}}};
	map<string,vector<int>>::iterator it=m1.find("neal");
	cout << it->first << endl;
	for (const auto& e : it->second)
		cout << e << endl;
	return 0;
}