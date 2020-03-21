#include"EX14.30(P506).h"
#include<iostream>
using std::cin; using std::cout; using std::endl;
int main()
{
	StrBlob s{ "hi","bye","now" };
	StrBlobPtr p(s, 1);
	cout << *p->begin() << endl;
	return 0;
}