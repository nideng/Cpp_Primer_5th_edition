#include<iostream>
#include<list>
#include<forward_list>
using namespace std;
int main()
{

	list<int>l1{ 0,1,2,3,4,5,6,7,8,9 };
	auto iter = l1.begin();
	while (iter != l1.end())
	{
		if (*iter % 2)
		{
			iter = l1.insert(iter, *iter);
			advance(iter, 2);
		}
		else
			iter = l1.erase(iter);
	}
	for (auto e : l1)
		cout << e << endl;
	cout << "====================" << endl;
	forward_list<int>flst{ 0,1,2,3,4,5,6,7,8,9 };
	auto prev = flst.before_begin();
	auto curr = flst.begin();
	while (curr != flst.end())
	{
		if ((*curr) % 2)
		{
			curr = flst.insert_after(curr, *curr);
			++curr;
			++prev;
		}
		else
		{
			curr = flst.erase_after(prev);
			++prev;
		}
	}
	for (auto e : flst)
		cout << e << endl;
	return 0;
}