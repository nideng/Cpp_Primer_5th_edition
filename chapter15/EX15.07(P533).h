#ifndef BOOK_SALES_H
#define BOOK_SALES_H
#include<string>
using std::string;
using std::size_t;
class Book_sales_base
{
public:
	Book_sales_base() = default;
	Book_sales_base(const string& b,double d,double p):
		bookNo(b),discount(d),price(p){}
	string isbn()const { return bookNo; }
	virtual double net_price(size_t n)const
	{
		return n * price*(1-discount);
	}
	virtual ~Book_sales_base() = default;
private:
	string bookNo;
protected:
	double price=0.0;
	double discount = 0.2;
};

class Book_sales_derive:public Book_sales_base {
public:
	Book_sales_derive() = default;
	Book_sales_derive(const string&, double,double,size_t);
	double net_price(size_t cnt)const
	{
		return max_num * (1 - discount) * price + (cnt - max_num) * price;
	}
private:
	size_t max_num=0;
};
Book_sales_derive::Book_sales_derive(const string& s,double d,double p,size_t n)
	:Book_sales_base(s,d,p),max_num(n){}
#endif // !BOOK_SALES_H
