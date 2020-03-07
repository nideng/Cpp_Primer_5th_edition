#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<string>
using namespace std;
void print(const vector<string>& words)
{
	for (const auto &e : words)
		cout << e << '\t';
	cout << endl;
}
bool isShorter(const string& s1, const string& s2)
{
	return s1.size() < s2.size();
}
void elimDups(vector<string>& words)
{
	sort(words.begin(), words.end());
	print(words);
	auto end_unique = unique(words.begin(), words.end());
	print(words);
	words.erase(end_unique, words.end());
	print(words);
}
int main()
{
	vector<string>vec = { "the","quick","red","fox","jumps","over","the","slow","red","turtle" };
	print(vec);
	elimDups(vec);
	stable_sort(vec.begin(), vec.end(), isShorter);
	print(vec);
	return 0;
}