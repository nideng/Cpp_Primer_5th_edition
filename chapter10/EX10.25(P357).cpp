#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<functional>
using namespace std;
using namespace std::placeholders;
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
bool check_size(const string& s, string::size_type sz)
{
	return s.size() >= sz;
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
	auto wc = partition(words.begin(), words.end(),bind(check_size,_1,sz));
	auto count = wc - words.begin();
	cout << count << " " << make_plural(count, "word", "s")
		<< " of length " << sz << " or longer" << endl;
	for_each(words.begin(), wc, [](const string& s) {cout << s << " "; });
	cout << endl;
}
int main()
{
	vector<string>vec = { "the","quick","red","fox","jumps","over","the","slow","red","turtle" };
	biggies(vec, 4);
	return 0;
}