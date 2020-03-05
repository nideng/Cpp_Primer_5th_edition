#include<iostream>
#include<list>
#include<vector>
using namespace std;
int main()
{
	list<const char*>l1{ "hello","world" };
	vector<string>vec1;
	vec1.assign(l1.cbegin(), l1.cend());
	for (const auto& e : vec1)
		cout << e << endl;
	return 0;
}
