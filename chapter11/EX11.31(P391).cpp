#include<iostream>
#include<map>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	multimap<string, string>authors;
	authors.insert({ "Barth,John","Sot-Weed Factor" });
	authors.insert({ "Barth,John","Lost in the Funhouse" });
	authors.insert({ "Lippman, Barbara","C++ Primer" });
	authors.insert({ "Lippman, Barbara","C++ Primer Plus" });
	auto p = authors.begin();
	while ((p = authors.find("Lippman, Barbara")) != authors.end())
	      authors.erase(p);
	for (const auto& e : authors)
		cout << e.first << '\t' << e.second << endl;
	return 0;
}
