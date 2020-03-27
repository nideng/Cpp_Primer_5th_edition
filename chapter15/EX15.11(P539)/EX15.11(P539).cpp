
#include"EX15.11(P539).h"
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
    Quote* quote_pointer = &bulk_quote;
    quote_pointer->debug();
    Quote& quote_reference = bulk_quote;
    quote_reference.debug();
    Quote quote = bulk_quote;
    quote.debug();
    return 0;
}