#include<iostream>
#include<map>
#include<set>
#include<string>
using namespace std;
bool check_char(const char ch)//check punctuation
{
	if(ispunct(ch))
		return true;
	return false;
}
void removes(string& s)//erase all the punctuation
{
	auto p = s.begin();
	while ((p =find_if(s.begin(),s.end(),check_char))!=s.end())
	{
		s.erase(p,p+1);
	}
}
int main()
{
	map<string, size_t>word_count;
	string word;
	while (cin >> word)
	{
		removes(word);
		for (auto& e : word)
			e=tolower(e);
		++word_count[word];
	}
	for (const auto& w : word_count)
		cout << w.first << " occurs " << w.second
		<< ((w.second > 1) ? " times" : " time") << endl;
	return 0;
}
