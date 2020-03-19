#include"EX13.31(P460).h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector<HasPtr>vec{ HasPtr("hello"),HasPtr("world"),HasPtr("c++")
	,HasPtr("primer") };
	sort(vec.begin(), vec.end());
	for (auto e : vec)
	{
		cout << e << endl;
	}
	return 0;
}