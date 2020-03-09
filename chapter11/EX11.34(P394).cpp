#include<iostream>
#include<map>
#include<fstream>
#include<sstream>
#include<string>
#include<algorithm>
#include<iterator>
using namespace std;
map<string, string>buildMap(ifstream& map_file)
{
	map<string, string>trans_map;
	string key;
	string value;
	while (map_file >> key && getline(map_file, value))
	{
		if (value.size() > 1)
			trans_map[key] = value.substr(1);
		else
			throw runtime_error("no rule for " + key);
	}
	return trans_map;
}
const string&
transform(const string& s, const map<string, string>& m)
{
		return m[s];
		//The above code won't compile because the subscript operator
		//might insert an element (when the element with the key s is 
		//not found), and we may use subscript only on a map that is
		//not const.
}
void word_transform(ifstream& map_file, ifstream& input)
{
	auto trans_map = buildMap(map_file);
	string text;
	while (getline(input, text))
	{
		istringstream stream(text);
		string word;
		bool firstword = true;
		while (stream >> word)
		{
			if (firstword)
				firstword = false;
			else
				cout << " ";
			cout << transform(word, trans_map);
		}
		cout << endl;
	}
}
int main()
{
	ifstream map_file("EX11.33(P394)_RULE.txt");
	ifstream input("EX11.33(P394)_TRANSFORM.txt");
	word_transform(map_file, input);
	return 0;
}





