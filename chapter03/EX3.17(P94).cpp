#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string str;
	vector<string>vec;
	while (cin >> str)
		vec.push_back(str);
	for (auto& i : vec)
		for (auto& j : i)
			j = toupper(j);
	for (auto i : vec)
		cout << i << endl;
	return 0;
}