#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int>vec;
	int i;
	while (cin >> i)
		vec.push_back(i);
	cin.clear();
	int j;
	cout << "The value needed to count: ";
	cin >> j;
	cout << "counts: " << count(vec.begin(), vec.end(), j) << endl;
	return 0;
}