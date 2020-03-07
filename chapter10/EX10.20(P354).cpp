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
void biggies(vector<string>& words, vector<string>::size_type sz)
{
	auto wc = count_if(words.begin(), words.end(),
		[sz](const string& a) {return a.size() > sz; });
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