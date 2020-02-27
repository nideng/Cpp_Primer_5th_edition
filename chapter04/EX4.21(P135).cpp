#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int i;
	vector<int>vec;
	while (cin >> i)
		vec.push_back(i);
	cout << "The origin vector:" << endl;
	for (auto e : vec)
		cout << e << endl;
	cout << "After change: " << endl;
	for (auto& e : vec)
	{
		e = ((e % 2) ? e * 2 : e);
		cout << e << endl;
	}
	return 0;
}