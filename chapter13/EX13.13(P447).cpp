#include<iostream>
#include<vector>
using namespace std;
struct X
{
	X() { cout << "X()" << endl; }
	X(const X&) { cout << "X(const X&)" << endl; }
	X& operator=(const X&) { cout << "X& operator=(const X&)" << endl; return *this; }
	~X() { cout << "~X()" << endl; }
};
X func1( X& x1)
{
	return x1;
}
X func2(X x2)
{
	return x2;
}
void func3(X x3)
{
	vector<X>vec;
	vec.push_back(x3);
}
void func4(X* x4)
{
	delete x4;
}
int main()
{
	X x1;
	X x2=func1(x1);
	func2(x2);
	func3(x2);
	func4(new X(x2));
	return 0;
}