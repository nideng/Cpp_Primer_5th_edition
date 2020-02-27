//EX1.09(P11)
/*
#include<iostream>
using std::cout;
using std::endl;
int main()
{
	int sum = 0;
	int val = 50;
	while (val <= 100)
	{
		sum += val;
		++val;
	}
	cout << "Sum of 50 to 100 is: " << sum << endl;
	return 0;
}
*/
//EX1.10(P11)
/*
#include<iostream>
using std::cout;
using std::endl;
int main()
{
	int val = 10, sum = 0;
	while (val >= 0)
	{
		sum += val;
		--val;
	}
	cout << "Sum of 0 to 10 is: " << sum << endl;
	return 0;
}
*/
//EX1.11(P11)
/*
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
void print_number(int i, int j)
{
	if (i > j)
		print_number(j, i);
	while (i <= j)
	{
		cout << i << endl;
		++i;
	}
}
int main()
{
	cout << "Enter two numbers(int): " << endl;
	int x, y;
	cin >> x >> y;
	cout << "The list of numbers between" << x << " and " << y << " is:" << endl;
	print_number(x, y);
	return 0;
}
*/
//EX2.41(P67)

#ifndef SALES_DATA_H
#define SALES_DATA_H
#include<string>
#include<iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::ostream;
using std::istream;
class Sales_data
{
public:
	Sales_data() :bookNo(""), bookName(""), units_sold(0), cost(0), price(0) {};
	Sales_data(const string&, const string&, unsigned, double, double);
	Sales_data(istream&);
	Sales_data(const Sales_data&);
	~Sales_data();
	Sales_data& operator+=(const Sales_data&);
	friend Sales_data operator+(const Sales_data&, const Sales_data&);
	friend ostream& operator<<(ostream&, const Sales_data&);
	friend istream& operator>>(istream&, Sales_data&);
	inline const string& isbn() const { return bookNo; }
	inline double revenue() const { return units_sold * (price - cost); }
private:
	string bookNo;//book number
	string bookName;
	unsigned units_sold;
	double cost;//book cost
	double price;
};
Sales_data::Sales_data(const string& s1, const string& s2, unsigned sell, double co, double pr)
	:bookNo(s1), bookName(s2), units_sold(sell), cost(co), price(pr) {}
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

Sales_data::Sales_data(istream& cin)
{
	cin >> *this;
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
	bookNo = s.bookNo;
	bookName = s.bookName;
	units_sold = s.units_sold;
	cost = s.cost;
	price = s.price;
}
Sales_data::~Sales_data()
{
}
#endif 

/*
#include<iostream>
#include"EX2.40(P65).h"

int main()
{
	Sales_data book;
	std::cin >> book;
	std::cout << book << std::endl;
	return 0;
}
*/
/*
#include<iostream>
#include"EX2.40(P65).h"
int main()
{
	Sales_data item1, item2;
	std::cin >> item1 >> item2;
	if (item1.isbn() == item2.isbn())
	{
		std::cout << item1 + item2 << std::endl;
		return 0;
	}
	else
	{
		std::cerr << "Data must refer to same ISBN"
			<< std::endl;
		return -1;
	}
}
*/
/*
#include<iostream>
#include"EX2.40(P65).h"
using std::cout;
using std::cin;
using std::endl;
int main()
{
	int Cnt = 1;
	Sales_data item1;
	if (cin >> item1)
	{
		Sales_data item2;
		while (cin >> item2)
		{
			if (item1.isbn() == item2.isbn())
				++Cnt;
			else
			{
				cout << item1 << " occurs " << Cnt << " times" << endl;
				//这种统计方式要求同一ISBN的记录必须聚在一起输入，待改进
				item1 = item2;
				Cnt = 1;
			}
		}
		cout << item1 << " occurs " << Cnt << " times" << endl;
	}
	return 0;
}
*/

int main()
{
	Sales_data item1, item2;
	if (std::cin >> item1)
	{
		while (std::cin >> item2)
		{
			if (item1.isbn() == item2.isbn())
				item1 += item2;
			else
			{
				std::cout << item1 << std::endl;
				item1 = item2;
			}
		}
		std::cout << item1 << std::endl;
	}
	else
	{
		std::cerr << "No data?!" << std::endl;
		return -1;
	}
	return 0;
}
