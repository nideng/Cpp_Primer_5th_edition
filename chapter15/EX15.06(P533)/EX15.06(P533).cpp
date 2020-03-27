#include"EX15.06(P533).h"
#include<iostream>
using std::ostream;
using std::endl;
using std::cout; using std::cin;

double print_total(ostream& os, const Quote& item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN:" << item.isbn() <<
		" # sold: " << n << " total due: " << ret << endl;
	return ret;
}
int main()
{
	Quote q("978-7-121-15535-2", 128.0);
	Bulk_Quote b("978-7-121-15535-2", 128.0, 50, 0.2);
	print_total(cout, q, 50);
	print_total(cout, b, 50);
	return 0;
}