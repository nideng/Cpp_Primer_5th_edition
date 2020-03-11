#include"EX12.03(P407).h"
#include<iostream>
using namespace std;
int main()
{
	StrBlob b1;
	StrBlob b2({ "a","an","the" });
	cout << b2.back() << endl;
	cout << b2.front() << endl;
	const StrBlob b3(b2);
	cout << b3.back() << endl;
	cout << b3.front() << endl;
	cout << "=================" << endl;
	cout << b2.size() << endl;
	b2.pop_back();
	cout << b2.size() << endl;
	cout << b3.size() << endl;
	b2.push_back("neal");
	return 0;
}
/*
You can certainly do this if you want to, but there doesn't seem 
to be any logical reason. The compiler doesn't complain because 
this doesn't modify data (which is a pointer) but rather the thing
data points to, which is perfectly legal to do with a const pointer.
by David Schwartz.
*/