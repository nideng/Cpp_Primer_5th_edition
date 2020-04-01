#include<iostream>
#include"Sales_data.h"
using std::cout; using std::endl;
template<typename T>
int compare(const T& lhs, const T& rhs)
{
	if (lhs < rhs)return -1;
	if (rhs < lhs)return 1;
	return 0;
}
int main()
{
	Sales_data s1("978-7-121-15535-2", 5, 128.0), s2("978-7-121-15535-3", 5, 98.0);
	//no match for 'operator<' (operand types are 'const Sales_data' and 'const Sales_data')
	cout << compare(s1, s2) << endl;
	return 0;
}