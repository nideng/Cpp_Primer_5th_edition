#include"EX13.03(P443).h"
#include<iostream>
using namespace std;
int main()
{
	StrBlob str({ "hello","world" });
	cout << str.count() << endl;
	StrBlob str_copy = str;
	cout << str.count() << endl;
	ConstStrBlobPtr p(str);
	cout << str.count() << endl;
	cout<<p.count() << endl;
	ConstStrBlobPtr p_copy(p);
	cout << str.count() << endl;
	cout<<p.count() << endl;
	return 0;
}
/*
when we copy a StrBlob, the shared_ptr member's use_count add one.
when we copy a StrBlobPrts, the weak_ptr member's use_count isn't changed.
(cause the count belongs to shared_ptr)
*/