#include<iostream>
#include<string>
#include<deque>
using namespace std;
int main()
{
	deque<string>de;
	string word;
	while (cin >> word)
		de.push_back(word);
	for (auto it = de.cbegin(); it != de.cend(); ++it)
		cout << *it << endl;
	return 0;
}