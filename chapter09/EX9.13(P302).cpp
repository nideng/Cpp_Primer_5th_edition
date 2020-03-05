#include<iostream>
#include<vector>
#include<list>
using namespace std;
int main()
{
	list<int>l1(5, 1);
	vector<int>vec1(5, 0);
	vector<double>vec2(vec1.begin(), vec1.end());
	for (const auto& i : vec2)
		cout << i << endl;
	cout << "===============================" << endl;
	vector<double>vec3(l1.begin(), l1.end());
	for (const auto& i : vec3)
		cout << i << endl;
	return 0;
}