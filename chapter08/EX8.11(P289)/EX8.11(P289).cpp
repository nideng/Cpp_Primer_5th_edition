#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
struct PersonInfo
{
	string name;
	vector<string>phones;
};
int main()
{
	string word, line;
	vector<PersonInfo>people;
	istringstream record;
	ifstream input("EX8.11(P289).txt");
	if (input)
	{
		while (getline(input, line))
		{
			PersonInfo info;
			record.str(line);
			record >> info.name;
			while (record >> word)
				info.phones.push_back(word);
			people.push_back(info);
			record.clear();
		}
	}
	for (auto& e : people)
	{
		cout << "Name: ";
		cout << e.name << endl;
		cout << "Phones: ";
		for (auto& i : e.phones)
			cout << i << endl;
		cout << "=========================" << endl;
	}
	return 0;
}