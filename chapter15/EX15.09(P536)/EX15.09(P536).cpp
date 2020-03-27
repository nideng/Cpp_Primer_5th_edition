/*The static type of a pointer or reference to a base class may differ from its dynamic type*/
#include"EX15.09(P536).h"
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

    Bulk_Quote bulk_quote("978-7-121-15535-2", 128.0, 50, 0.2);

    // The pointer is of static type Quote, but it's dynamic type is Bulk Quote
    // Because of polymorphism the Bulk Quote implementation of the net_price()
    // method gets called.
    Quote* quote_pointer = &bulk_quote;
    cout << quote_pointer->net_price(50) << endl;

    // The reference is of static type Quote, but it's dynamic type is Bulk Quote
    // Like with the pointer, the Bulk Quote implementation of the net_price()
    // method gets called.
    Quote& quote_reference = bulk_quote;
    cout<<quote_reference.net_price(50)<<endl;

    // The static type of this variable is Quote. Here the Bulk Quote object
    // gets upcasted. The Quote part of bulk_quote gets copied into quote, but
    // the rest is not handled. Because of the cast the Quote implementation of
    // the net_price() method gets called.
    Quote quote = bulk_quote;
    cout<<quote.net_price(50)<<endl;
	return 0;
}