#include<algorithm>
#include<string>
#include<iostream>
#include<list>
using namespace std;

int main()
{
	list<string>l1;
	string i;
	while (cin >> i)
		l1.push_back(i);
	cin.clear();
	string j;
	cout << "The value needed to count: ";
	cin >> j;
	cout << "counts: " << count(l1.begin(), l1.end(), j) << endl;
	return 0;
}