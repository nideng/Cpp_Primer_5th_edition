#include "EX14.10(P496).h"

Sales_data::Sales_data(std::istream& is) : Sales_data()
{
    is >> *this;
}

Sales_data& Sales_data::operator+=(const Sales_data& rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

std::istream& operator>>(std::istream& is, Sales_data& item)
{
    double price = 0.0;
    is >> item.bookNo >> item.units_sold >> price;
    if (is)
        item.revenue = price * item.units_sold;
    else
        item = Sales_data();
    return is;
}

std::ostream& operator<<(std::ostream& os, const Sales_data& item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs)
{
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

int main()
{
    Sales_data s(std::cin);
    std::cout << s << std::endl;
    return 0;
}
/*
(a)correct;
(b)ilegal input. But .95 will be converted to a float stored 
    in this object. As a result, the data inside will be a 
    wrong one. Output: 10 24 22.8 0.95
*/