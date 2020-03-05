#include<iostream>
#include<forward_list>
#include<string>
using namespace std;
void func(forward_list<string> &flst, const string& s1, const string& s2)
{
	bool i = true;
	auto prev = flst.before_begin();
	auto curr = flst.begin();
	while (curr != flst.end())
	{
		if (*curr == s1)
		{
			i = false;
			++prev;
			curr = flst.insert_after(curr, s2);
		}
		else
		{
			++curr;
			++prev;
		}
	}
	if (i)
		flst.insert_after(prev, s2);
}
int main()
{
	forward_list<string>flst{ "hello","neal", "world","neal" };
	func(flst, "neal", "how");
	for (auto e : flst)
		cout << e << endl;
	return 0;
}