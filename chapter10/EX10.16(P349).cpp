#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
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
string make_plural(size_t ctr, const string& word, const string& ending)
{
	return (ctr > 1) ? word + ending : word;
}
void elimDups(vector<string>& words)
{
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}
void biggies(vector<string>& words, vector<string>::size_type sz)
{
	elimDups(words);
	stable_sort(words.begin(), words.end(),
		[](const string& a, const string& b) { return a.size() < b.size(); });
	auto wc = find_if(words.begin(), words.end(),
		[sz](const string& a) {return a.size() >= sz; });
	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "word", "s")
		<< " of length " << sz << " or longer" << endl;
	for_each(wc, words.end(), [](const string& s) {cout << s << " "; });
	cout << endl;
}
int main()
{
	vector<string>vec = { "the","quick","red","fox","jumps","over","the","slow","red","turtle" };
	biggies(vec, 4);
	return 0;
}