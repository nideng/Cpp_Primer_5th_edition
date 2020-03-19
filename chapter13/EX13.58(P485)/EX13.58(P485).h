#ifndef FOO_H
#define FOO_H
#include<vector>
#include<algorithm>
#include<iostream>
using std::cout;  using std::endl;
using std::vector;
using std::istream;
using std::cin;
class Foo
{
public:
	Foo(istream&);
	Foo sorted()&&;
	Foo sorted()const&;
private:
	vector<int>data;
};
Foo::Foo(istream& in)
{
	int i;
	while (in >> i)
		data.push_back(i);
}
Foo Foo::sorted()&&
{
	sort(data.begin(), data.end());
	cout << "call sorted() &&" << endl;
	return *this;
}
Foo Foo::sorted()const&
{
	cout << "call sorted()const &" << endl;
	return Foo(*this).sorted();
}
#endif