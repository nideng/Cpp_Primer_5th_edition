#include<iostream>
#include<string>
#include<list>
using namespace std;
int main()
{
	list<string>l1;
	string word;
	while (cin >> word)
		l1.push_back(word);
	for (auto it = l1.cbegin(); it != l1.cend(); ++it)
		cout << *it << endl;
	return 0;
}