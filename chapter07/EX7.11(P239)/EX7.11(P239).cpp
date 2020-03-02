#include"EX7.11(P239).h"
#include<iostream>
using namespace std;
int main()
{
	Sales_data s1;
	Sales_data s2("978-7-121-15535-2", "C++ Primer(5th)", 50, 52.5, 128.0);
	Sales_data s3(s2);
	Sales_data s4(cin);
	return 0;
}