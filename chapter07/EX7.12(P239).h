#ifndef SALES_DATA_H
#define SALES_DATA_H
#include<string>
#include<iostream>
using namespace std;
class Sales_data
{
public:
	Sales_data() :bookNo(""), bookName(""), units_sold(0), cost(0), price(0)
	{
		cout << "call the function of Sales_data()" << endl;
	};
	Sales_data(const string&, const string&, unsigned, double, double);
	Sales_data(istream& is) { is >> *this; }
	Sales_data(const Sales_data&);
	~Sales_data();
	Sales_data& operator+=(const Sales_data&);
	Sales_data& combine(const Sales_data&);
	inline const string& isbn() const { return bookNo; }
	inline double revenue() const { return units_sold * (price - cost); }
	friend Sales_data operator+(const Sales_data&, const Sales_data&);
	friend ostream& operator<<(ostream&, const Sales_data&);
	friend istream& operator>>(istream&, Sales_data&);
	friend istream& read(istream& is, Sales_data& item);
	friend Sales_data add(const Sales_data& lhs, const Sales_data& rhs);
	friend ostream& print(ostream& os, const Sales_data& item);
private:
	string bookNo;//book number
	string bookName;
	unsigned units_sold;
	double cost;//book cost
	double price;
};
Sales_data::Sales_data(const string& s1, const string& s2, unsigned sell, double co, double pr)
	:bookNo(s1), bookName(s2), units_sold(sell), cost(co), price(pr)
{
	cout << "call the function of Sales_data(cosnt string&,const string&,unsigned,double,double)" << endl;
}
istream& operator>>(istream& is, Sales_data& s)
{

	is >> s.bookNo >> s.bookName >> s.units_sold >> s.cost >> s.price;
	return is;
}
ostream& operator<<(ostream& os, const Sales_data& s)
{
	os << s.bookNo << '\t' << s.bookName << endl;
	os << s.units_sold << '\t' << s.price << '\t' << s.revenue() << endl;
	return os;
}

Sales_data& Sales_data::operator+=(const Sales_data& s1)
{
	price = (s1.price * s1.units_sold + price * units_sold) / (units_sold + s1.units_sold);
	cost = (s1.cost * s1.units_sold + cost * units_sold) / (units_sold + s1.units_sold);
	units_sold += s1.units_sold;
	return *this;
}
Sales_data operator+(const Sales_data& s1, const Sales_data& s2)
{
	Sales_data s3(s1);
	s3 += s2;
	return s3;
}
Sales_data::Sales_data(const Sales_data& s)
{
	cout << "call the function of Sales_data(const Sales data&)" << endl;
	bookNo = s.bookNo;
	bookName = s.bookName;
	units_sold = s.units_sold;
	cost = s.cost;
	price = s.price;
}
Sales_data add(const Sales_data& lhs, const Sales_data& rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}
istream& read(istream& is, Sales_data& item)
{
	is >> item;
	return is;
}
ostream& print(ostream& os, const Sales_data& item)
{
	os << item;
	return os;
}
Sales_data::~Sales_data()
{
}
Sales_data& Sales_data::combine(const Sales_data& rhs)
{
	*this += rhs;
	return *this;
}
#endif 
