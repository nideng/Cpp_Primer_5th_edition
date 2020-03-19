#include<iostream>
#include"EX13.54(P481).h"
using namespace std;
int main()
{
	HasPtr h1("hello");
	HasPtr h2;
	h2 = std::move(h1);//error: ambiguous overload for 'operator='
}