#include"StrBlobPtr.h"
#include"StrBlobPtrPtr.h"
#include<iostream>
using namespace std;
int main()
{
	StrBlob s{ "hi","bye","now" };
	StrBlobPtr s1(s,1);
	StrBlobPtrPtr s2(s1);
	std::cout << *s2->operator++() << endl;
}