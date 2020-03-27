#include"EX15.07(P533).h"
#include<iostream>
using std::ostream;
using std::cin; using std::cout; using std::endl;
void print_total(ostream& os, const Book_sales_base& item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n
		<< " total due: " << ret << endl;
}
int main()
{
	Book_sales_base q("978-7-121-15535-2",0.2,128.0);
	Book_sales_derive b("978-7-121-15535-2",0.2,128.0, 50);
	print_total(cout, q, 60);
	print_total(cout, b, 60);
	Book_sales_base s;
	return 0;
}