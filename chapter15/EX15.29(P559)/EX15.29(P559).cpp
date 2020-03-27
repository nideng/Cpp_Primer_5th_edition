#include"EX15.29(P559).h"
#include<vector>
#include<iostream>
#include<numeric>
#include<memory>
using std::cout; using std::endl;
using std::vector;
using std::accumulate;
using std::shared_ptr; using std::make_shared;
int main()
{
	vector<shared_ptr<Quote>>vec;
	vec.push_back(make_shared<Quote>("978-7-121-15535-2", 128.0));
	vec.push_back(make_shared<Bulk_Quote>("978-7-121-15535-2", 128.0, 50, 0.2));
	auto total = accumulate(vec.cbegin(), vec.cend(), 0.0, [](double ret, const shared_ptr<Quote>obj) { return ret += obj->net_price(50); });
	cout << total << endl;
	return 0;
}
/*
the result is different;
Because derived objects are "sliced down" when assigned to a base - type object.
Thus, when put Bulk_quote object into the vector of Quote, all the object "slice down" to Quote.

If we want to holds objects related by inheritance, we should define the vector to hold pointers(preferable smart pointers)
to the base class.So, the vector contains are dynamic type of the objects.
*/