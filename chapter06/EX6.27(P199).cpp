#include<iostream>
using namespace std;

int sum(const initializer_list<int>&i)
{
	int sum = 0;
	for (auto e : i)
		sum += e;
	return sum;
}

int main()
{
	cout << sum({ 1,2,3 ,4,5,6}) << endl;
	return 0;
}