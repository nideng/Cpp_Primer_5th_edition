#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<functional>
using namespace std::placeholders;
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
bool check_size(const string& s, string::size_type sz)
{
	return s.size() <= sz;
}
void biggies(vector<string>& words, vector<string>::size_type sz)
{
	auto wc = count_if(words.begin(), words.end(),bind(check_size,_1,sz));
	cout << wc << " " << make_plural(wc, "word", "s")
		<< " of length " << sz << " or longer" << endl;
	cout << endl;
}
int main()
{
	vector<string>vec = { "the","quick","red","fox","jumps","over","the","slow","red","turtles" };
	biggies(vec, 6);
	return 0;
}