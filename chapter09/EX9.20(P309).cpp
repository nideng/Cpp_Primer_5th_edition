#include<list>
#include<deque>
#include<iostream>
using namespace std;
int main()
{
	list<int>l1{ 1,3,4,5,7,9,12 };
	deque<int>de1, de2;
	for (auto i : l1)
		if (i % 2) de1.push_back(i);
		else de2.push_back(i);
	/*
	//a better method
	    for (auto i : l1)
        (i & 0x1 ? odd : even).push_back(i);
	*/
	for (auto e : de1)
		cout << e << endl;
	cout << "============================" << endl;
		for (auto e : de2)
			cout << e << endl;
}