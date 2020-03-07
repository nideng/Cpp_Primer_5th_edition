#include<iostream>
using namespace std;
int main()
{
	int i = 42;
	auto f = [&i]()mutable->int
	{
		while ([i]() {return i > 0; }())  --i;
		return i;
	};
	cout << f() << endl;
	cout << "=========================" << endl;
	//a better answer
	int j = 42;
	auto check_and_decrement = [&j]() { return j > 0 ? !--j : !j; };
	while (!check_and_decrement())
		cout << j << " ";
	cout << j << endl;
}