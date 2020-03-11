#include<memory>
#include<iostream>
#include<string>
using namespace std;
int main()
{
	allocator<string>alloc;
	int n=5;
	string s;
	auto const p = alloc.allocate(n);
	cout << typeid(p).name() << endl;
	auto q = p;
	while (q != p + n)
	{
		cin >> s;
		alloc.construct(q++, s);
	}
	while (q != p)
	{
		cout << *(--q) << endl;
		alloc.destroy(q);
	}
	alloc.deallocate(p, n);
	return 0; 
}
