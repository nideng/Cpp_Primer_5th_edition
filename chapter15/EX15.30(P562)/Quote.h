#ifndef QUOTE_H
#define QUOTE_H
#include<string>
#include<iostream>
using std::string;
using std::size_t;
class Quote
{
public:
	Quote() = default;
	Quote(const string& book, double sales_price) :
		bookNo(book), price(sales_price) {}
	string isbn()const { return bookNo; }
	virtual Quote* clone()const& { return new Quote(*this); }
	virtual Quote* clone()&& { return new Quote(std::move(*this)); }
	virtual double net_price(size_t n) const
	{
		return n * price;
	}
	virtual void debug() const { std::cout << "Data member:\n" << "bookNo: " << bookNo << '\n' << "price: " << price << std::endl; }
	virtual ~Quote() = default;
private:
	string bookNo;
protected:
	double price = 0.0;
};

class Disc_quote :public Quote
{
public:
	Disc_quote() = default;
	Disc_quote(const string& book, double price,
		size_t qty, double disc) :Quote(book, price), quantity(qty), discount(disc) {}
	double net_price(size_t)const = 0;
protected:
	size_t quantity = 0;
	double discount = 0.0;
};
class Bulk_Quote :public Disc_quote
{
public:
	using Disc_quote::Disc_quote;
	virtual Bulk_Quote* clone()const& { return new Bulk_Quote(*this); }
	virtual Bulk_Quote* clone()&& { return new Bulk_Quote(std::move(*this)); }
	double net_price(size_t)const override;
	void debug()const override;
};
double Bulk_Quote::net_price(size_t cnt)const
{
	if (cnt >= quantity)
		return cnt * (1 - discount) * price;
	else
		return cnt * price;
}
void Bulk_Quote::debug()const
{
	Quote::debug();
	std::cout << "min_qty: " << quantity << '\n' << "discount: " << discount << std::endl;
}
#endif // !"QUOTE_H"
