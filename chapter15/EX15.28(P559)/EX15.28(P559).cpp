#include"EX15.28(P559).h"
#include<vector>
#include<iostream>
#include<numeric>
using std::cout; using std::endl;
using std::vector;
using std::accumulate;
int main()
{
	vector<Quote>vec;
	vec.push_back(Quote("978-7-121-15535-2",128.0));
	vec.push_back(Bulk_Quote("978-7-121-15535-2", 128.0, 50, 0.2));
	auto total = accumulate(vec.cbegin(), vec.cend(), 0.0, [](double ret, const Quote & obj){ return ret += obj.net_price(50); });
	cout << total << endl;
	return 0;
}