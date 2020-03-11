#include"EX12.22(P423).h"
#include<iostream>
using namespace std;
int main()
{
	StrBlob p({ "a","bcd","efgh" });
	ConstStrBlobPtr b = p.begin();
	cout << b.deref() << endl;
	return 0;
}