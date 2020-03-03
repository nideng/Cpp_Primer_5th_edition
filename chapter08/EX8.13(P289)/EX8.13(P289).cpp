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

bool valid(const string& s)
{
	for (const auto& e : s)
	{
		if (isdigit(e)) continue;
		else return false;
	}
	return true;
}
string format(const string& s)
{
	return s.substr(0, 3) + "-" + s.substr(3, 3) + "-" + s.substr(6);
}


int main()
{
	string word, line;
	vector<PersonInfo>people;
	ifstream input("EX8.13(P289).txt");
	if (input)
	{
		while (getline(input, line))
		{
			PersonInfo info;
			istringstream record(line);
			record >> info.name;
			while (record >> word)
				info.phones.push_back(word);
			people.push_back(info);
		}
	}
	for (const auto& entry : people)
	{
		ostringstream formatted, badNums;
		for (const auto& nums : entry.phones)
		{
			if (!valid(nums))
			{
				badNums << " " << nums;
			}
			else
			{
				formatted << " " << format(nums);
			}
		}
		if (badNums.str().empty())
			cout << entry.name << " " << formatted.str() << endl;
		else
			cerr << "input error: " << entry.name
			<< " invalid number(s)" << badNums.str() << endl;
	}
	return 0;
}
