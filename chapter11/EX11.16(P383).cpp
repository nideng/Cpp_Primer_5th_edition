#include<iostream>
#include<map>
#include<iterator>
using namespace std;
int main()
{
	map<int, int>m1;
	for (int i = 0; i < 10; ++i)
		m1[i] = i + 1;
	for (auto it = m1.begin(); it != m1.end(); ++it)
		it->second = 0;
	for (const auto& e : m1)
		cout << e.first << '\t' << e.second << endl;
	return 0;
}