#include<iostream>
#include"EX10.32(P362).h"
#include<vector>
#include<string>
#include<algorithm>
#include<iterator>
#include<numeric>
using namespace std;
int main()
{
	istream_iterator<Sales_item>item_iter(cin), eof;
	ostream_iterator<Sales_item>item_outer(cout, "\n");
	vector<Sales_item>vec;
	copy(item_iter, eof, back_inserter(vec));
	sort(vec.begin(), vec.end(), compareIsbn);
	auto first = vec.begin();
	auto end = vec.begin();
	while (first != vec.end())
	{
		end = find_if(first, vec.end(), [&first](const Sales_item& s) {return first->isbn() != s.isbn(); });
		item_outer=accumulate(first, end, Sales_item(first->isbn()));
		first = end;
	}
	return 0;
}