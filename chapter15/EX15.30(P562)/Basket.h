#include"Quote.h"
#include<set>
#include<ostream>
#include<memory>
using std::multiset;
using std::ostream; using std::cout; using std::endl;
using std::shared_ptr;
double print_total(ostream& os, const Quote& item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n
		<< " total due: " << ret << endl;
	return ret;
}
class Basket {
public:
	void add_item(const std::shared_ptr<Quote>& sale)
	{
		items.insert(sale);
	}
	void add_item(const Quote& sale) // copy the given object
	{
		items.insert(std::shared_ptr<Quote>(sale.clone()));
	}
	void add_item(Quote&& sale)      // move the given object
	{
		items.insert(
			std::shared_ptr<Quote>(std::move(sale).clone()));
	}
	double total_recepit(ostream&)const;
private:
	static bool compare(const shared_ptr<Quote>& lhs, const shared_ptr<Quote>& rhs) { return lhs->isbn() < rhs->isbn(); }
	multiset<shared_ptr<Quote>, decltype(compare)*>items{ compare };
};
double Basket::total_recepit(ostream& os)const
{
	double sum = 0.0;
	for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter)) {
		sum += print_total(os, **iter, items.count(*iter));
	}
	os << "Total Sale: " << sum << endl;
	return sum;
}