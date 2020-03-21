#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<iostream>
#include<algorithm>
using std::string;
using std::cout; using std::endl;
using std::vector;
class string_sizes
{
public:
	string_sizes(size_t l, size_t u, size_t n = 0) :lower(l), upper(u), nums(n) {}
	void operator()(const string& s)
	{
		if ((s.size() <= upper) && (s.size() >= lower))
			++nums;
	}
	void print()const { cout << nums; }
private:
	size_t lower;
	size_t upper;
	size_t nums;
};
int main()
{
	std::ifstream input("EX14.39(P509).txt");
	string word;
	vector<string_sizes>vec{ string_sizes(1,9),string_sizes(10,100) };
	while (input >> word)
	{
		for (auto& e : vec)
			e(word);
	}
	for (auto& e : vec)
	{
		e.print();
		std::cout << endl;
	}
	return 0;
}