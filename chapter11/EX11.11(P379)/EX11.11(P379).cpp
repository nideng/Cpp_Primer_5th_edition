#include "EX11.11(P379).h"
#include <set>
using namespace std;
bool compareIsbn(const Sales_data & lhs, const Sales_data & rhs)
{
    return lhs.isbn() < rhs.isbn();
}
int main()
{
    using com = bool (*)(Sales_data const&, Sales_data const&);
    multiset<Sales_data, com>boostore(compareIsbn);
    return 0;
}