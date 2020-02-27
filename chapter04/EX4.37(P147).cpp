#include<iostream>
using namespace std;
int main()
{
	int i; double d; const string* ps; char* pc; void* pv;
	pv = static_cast<void*>(const_cast<string*>(ps));//(a)
	i = static_cast<int>(*pc);//(b)
	pv = static_cast<void*>(&d);//(c)
	pc = static_cast<char*>(pv);//(d)
}