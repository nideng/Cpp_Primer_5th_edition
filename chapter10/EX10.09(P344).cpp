#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
void print(const vector<string>& words)
{
	for (auto e : words)
		cout << e << '\t';
	cout << endl;
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
	return 0;
}