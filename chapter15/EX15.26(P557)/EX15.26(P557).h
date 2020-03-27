#ifndef QUOTE_H
#define QUOTE_H
#include<string>
#include<iostream>
using std::string;
using std::size_t;
class Quote
{
public:
	Quote(){ std::cout << "call Quote()" << std::endl; }
	Quote(const Quote& q) :bookNo(q.bookNo), price(q.price) { std::cout << "call Quote(const Quote&)" << std::endl; }
	Quote(Quote&& q)noexcept:bookNo(std::move(q.bookNo)),price(std::move(q.price)){ std::cout << "call Quote(Quote&&)" << std::endl; }
	Quote& operator=(const Quote& q) {
		bookNo = q.bookNo; price = q.price; 
		std::cout << "call Quote& operator=(const Quote&)" << std::endl; 
		return *this; 
	}
	Quote& operator=(Quote&& q)noexcept
	{ 
		bookNo = std::move(q.bookNo); 
		price = std::move(q.price);
		std::cout << "call Quote& operator=(Quote&&)" << std::endl; 
		return *this;
	}
	Quote(const string& book, double sales_price) :
		bookNo(book), price(sales_price) {}
	string isbn()const { return bookNo; }
	virtual double net_price(size_t n) const
	{
		return n * price;
	}
	virtual void debug() const { std::cout << "Data member:\n" << "bookNo: " << bookNo << '\n' << "price: " << price << std::endl; }
	virtual ~Quote() { std::cout << "call ~Quote()" << std::endl; };
private:
	string bookNo;
protected:
	double price = 0.0;
};

class Disc_quote :public Quote
{
public:
	Disc_quote() { std::cout << "call Disc_Quote()" << std::endl; };
	Disc_quote(const Disc_quote& d)
		:Quote(d),quantity(d.quantity),discount(d.discount){
		std::cout << "call Disc_Quote(const Disc_Quote&)" << std::endl;
	}
	Disc_quote(Disc_quote&& d)noexcept
		:Quote(std::move(d)), quantity(std::move(d.quantity)), discount(std::move(d.discount)) {
		std::cout << "call Disc_Quote(Disc_Quote&&)" << std::endl;
	}
	Disc_quote& operator=(const Disc_quote& d)
	{
		Quote::operator=(d);
		quantity = d.quantity;
		discount = d.discount;
		std::cout << "call Disc_Quote& operator=(const Disc_Quote&)" << std::endl;
		return *this;
	}
	Disc_quote& operator=(Disc_quote&& d)noexcept
	{
		Quote::operator=(std::move(d));
		quantity =std::move(d.quantity);
		discount = std::move(d.discount);
		std::cout << "call Disc_Quote& operator=(Disc_Quote&&)" << std::endl;
		return *this;
	}
	Disc_quote(const string& book, double price,
		size_t qty, double disc) :Quote(book, price), quantity(qty), discount(disc) {}
	double net_price(size_t)const = 0;
	virtual ~Disc_quote() { std::cout << "call ~Disc_quote()" << std::endl; }
protected:
	size_t quantity = 0;
	double discount = 0.0;
};
class Bulk_Quote :public Disc_quote
{
public:
	Bulk_Quote() { std::cout << "call Bulk_Quote()" << std::endl; };
	Bulk_Quote(const Bulk_Quote& b)
		:Disc_quote(b) {
		std::cout << "call Bulk_Quote(cosnt Bulk_Quote&)" << std::endl;
	}
	Bulk_Quote(Bulk_Quote&& b)noexcept
		:Disc_quote(std::move(b)) {
		std::cout << "call Bulk_Quote(Bulk_Quote&&)" << std::endl;
	}
	Bulk_Quote& operator=(const Bulk_Quote& b)
	{
		Disc_quote::operator=(b);
		std::cout << "call Bulk_Quote& operator=(cosnt Bulk_Quote&)" << std::endl;
		return *this;
	}
	Bulk_Quote& operator=(Bulk_Quote&& b)noexcept
	{
		Disc_quote::operator=(std::move(b));
		std::cout << "call Bulk_Quote& operator=(Bulk_Quote&&)" << std::endl;
		return *this;
	}
	~Bulk_Quote() { std::cout << "call ~Bulk_Quote()" << std::endl; }
	Bulk_Quote(const string&, double, size_t, double);
	double net_price(size_t)const override;
	void debug()const override;
};
Bulk_Quote::Bulk_Quote(const string& book, double p, size_t qty, double disc)
	:Disc_quote(book, p, qty, disc) {}
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
