#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;
int main()
{
	string not_ascender_and_descender("aceimnorsuvwxz");
	ifstream input("EX9.49(P327).txt");
	if (input)
	{
		string line, word;
		string longestword;
		while (getline(input, line))
		{
			istringstream record(line);
			while (record >> word)
			{
				if( word.find_first_not_of(not_ascender_and_descender)== word.npos)
				{
					if (word.size() > longestword.size())
						longestword = word;
				}
			}
		}
		if (longestword.empty())
			cout << "all words are ascender or descender" << endl;
		else
			cout << "The longset word is: " << longestword << endl;
	}
	return 0;
}