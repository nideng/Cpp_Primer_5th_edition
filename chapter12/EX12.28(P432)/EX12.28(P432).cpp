#include<iostream>
#include<fstream>
#include<sstream>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<memory>
using namespace std;
void result_map(ifstream& infile,map<string,set<unsigned>>&m1,vector<string>&v1)
{
	string lines,word;
	while (getline(infile,lines))
	{
		v1.push_back(lines);
		auto n = v1.size() - 1;
		istringstream in(lines);
		while (in >> word)
		{
			m1[word].insert(n);
		}
	}
}
void runQueries(map<string, set<unsigned>>& m1, vector<string>& v1)
{
	while (true)
	{
		cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q") break;
		else
		{
			auto it = m1.find(s);
			if (it == m1.end())
				cout << s << " occurs " << 0 << " time" << endl;
			else
			{
				cout << s << " occurs " << it->second.size() <<
					((it->second.size() > 1) ? " times" : " time") << endl;
				for (auto e : it->second)
					cout << "\t(line " << e + 1 << ") "
					<< v1[e] << endl;
			}
		}
	}
}
int main()
{
	ifstream infile("EX12.28(P432).txt");
	map<string, set<unsigned>> m1;
	vector<string> v1;
	result_map(infile, m1, v1);
	runQueries(m1, v1);
	return 0;
}
