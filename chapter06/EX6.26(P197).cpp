#include<iostream>
#include<sstream>
#include<string>
#include<map>
using namespace std;
map<char, char>m1{ {',',' '},{'/',' '} };
int main()
{
	string str1("January 1,1990");
	for (auto& e : str1)
	{
		auto map_it = m1.find(e);
		if (map_it != m1.end())
			e = map_it->second;
	}
	istringstream in(str1);
	string word;
	while (in >> word)
		cout << word << endl;
	return 0;
}