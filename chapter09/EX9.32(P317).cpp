//visual studio
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int>v1{ 0,1,2,3,4,5,6,7,8,9 };
	auto iter = v1.begin();
	while (iter != v1.end())
	{
		if (*iter % 2)
		{
			iter = v1.insert(iter, *iter++);//the code can run successfully
			iter++;
		}
		else
			iter = v1.erase(iter);
	}
	for (auto e : v1)
		cout << e << endl;
	return 0;
}
/*
As a result, after entering function insert,
iter could be its original value or original value + 1 or even anything 
else, depending on how compiler implemented.
*/