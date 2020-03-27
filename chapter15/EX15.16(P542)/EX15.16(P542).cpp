#include"EX15.16(P542).h"
#include<iostream>
using std::ostream;
using std::cin; using std::cout; using std::endl;
void print_total(ostream& os, const Quote& item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n
		<< " total due: " << ret << endl;
}
int main()
{
	Quote q("978-7-121-15535-2", 128.0);
	Bulk_Quote b("978-7-121-15535-2", 128.0, 50, 0.2);
	Limit_quote l("978-7-121-15535-2", 128.0, 50, 0.2);
	print_total(cout, q, 60);
	print_total(cout, b, 60);
	print_total(cout, l, 60);
	return 0;
}