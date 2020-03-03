#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	vector<string>vec;
	string line, word;
	ifstream input("EX8.10(P289).txt");
	if (input)
	{
		while (getline(input, line))
			vec.push_back(line);
	}
	for(const auto&e:vec)
	{
		istringstream record(e);
		while (record >> word)
			cout << word << endl;
	}
	return 0;
}
