#include<iostream>
#include<map>
#include<set>
#include<string>
using namespace std;
int main()
{
	map<string, size_t>word_count;
	string word;
	while (cin >> word)
	{
		auto it=word_count.insert({ word,1 });
		if (!it.second)
			++(it.first->second);
	}
	for (const auto& w : word_count)
		cout << w.first << " occurs " << w.second
		<< ((w.second > 1) ? " times" : " time") << endl;
	return 0;
}