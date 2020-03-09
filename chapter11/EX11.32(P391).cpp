#include<iostream>
#include<map>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
using namespace std;
int main()
{
	multimap<string, string>authors;
	authors.insert({ "Lippman, Barbara","C++ Primer" });
	authors.insert({ "Barth,John","Sot-Weed Factor" });
	authors.insert({ "Barth,John","Lost in the Funhouse" });
	authors.insert({ "Lippman, Barbara","C++ Primer Plus" });
	authors.insert({ "Lippman, Barbara","Effective C++" });
	authors.insert({ "Lippman, Barbara","C++ Primer Plus" });
	map<string, multiset<string>>order_authors;
	for (const auto& e : authors)
		order_authors[e.first].insert({e.second});
	for (const auto& e : order_authors)
	{
		cout << e.first << '\t';
		for (const auto& i : e.second)
			cout << i << '\t';
		cout << endl;
	}
	return 0;
}