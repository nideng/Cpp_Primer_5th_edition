#include "EX14.13(P497).h"
#include<stdexcept>
using std::invalid_argument;
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

Sales_data& Sales_data::operator-=(const Sales_data& rhs)
{
    if (units_sold < rhs.units_sold)
        throw invalid_argument("units_sold is bigger than the one be substrated");
    units_sold -= rhs.units_sold;
    revenue -= rhs.revenue;
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

Sales_data operator-(const Sales_data& lhs, const Sales_data& rhs)
{
    Sales_data sub = lhs;
    sub -= rhs;
    return sub;
}
int main()
{
    Sales_data s(std::cin);
    std::cout << s << std::endl;
    return 0;
}
