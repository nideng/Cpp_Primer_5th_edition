#include"EX12.02(P407).h"
#include<iostream>
using namespace std;
int main()
{
	StrBlob b1;
	StrBlob b2({ "a","an","the" });
	cout<<b2.back()<<endl;
	cout << b2.front() << endl;
	const StrBlob b3(b2);
	cout << b3.back() << endl;
	cout << b3.front() << endl;
	cout << "=================" << endl;
	cout << b2.size() << endl;
	b2.pop_back();
	cout << b2.size() << endl;
	cout << b3.size() << endl;
	return 0;
}