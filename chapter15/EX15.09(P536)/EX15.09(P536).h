#ifndef QUOTE_H
#define QUOTE_H
#include<string>
using std::string;
using std::size_t;
class Quote
{
public:
	Quote() = default;
	Quote(const string& book, double sales_price) :
		bookNo(book), price(sales_price) {}
	string isbn()const { return bookNo; }
	virtual double net_price(size_t n) const
	{
		return n * price;
	}
	virtual ~Quote() = default;
private:
	string bookNo;
protected:
	double price = 0.0;
};
class Bulk_Quote :public Quote
{
public:
	Bulk_Quote() = default;
	Bulk_Quote(const string&, double, size_t, double);
	double net_price(size_t)const override;
private:
	size_t min_qty = 0;
	double discount = 0.0;
};
Bulk_Quote::Bulk_Quote(const string& book, double p, size_t qty, double disc)
	:Quote(book, p), min_qty(qty), discount(disc) {}
double Bulk_Quote::net_price(size_t cnt)const
{
	if (cnt >= min_qty)
		return cnt * (1 - discount) * price;
	else
		return cnt * price;
}

#endif // !"QUOTE_H"
