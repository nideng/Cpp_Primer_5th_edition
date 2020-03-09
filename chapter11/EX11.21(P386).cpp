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
		++word_count.insert({ word,0 }).first->second;
	}
	for (const auto& w : word_count)
		cout << w.first << " occurs " << w.second
		<< ((w.second > 1) ? " times" : " time") << endl;
	return 0;
}
/*
This code can be explained like this pseudocode:
while reading into word
	if word_count has key word:
		word_count[word] += 1
	else:
		word_count[word] = 0
		word_count[word] += 1
*/