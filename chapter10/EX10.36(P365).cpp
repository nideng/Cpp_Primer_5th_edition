#include<iostream>
#include<list>
#include<iterator>
using namespace std;
int main()
{
	list<int>l1{ 0,1,2,3,4,5,6,7,8,9,10 };
	auto it=find(l1.crbegin(), l1.crend(), 0);
	cout << distance(it, l1.crend()) << endl;
	return 0;
}