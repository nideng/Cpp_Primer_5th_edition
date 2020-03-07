#include<iostream>
#include"EX10.12(P345).h"
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
inline bool compareIsbn(const Sales_data& s1, const Sales_data& s2)
{
	return s1.isbn() < s2.isbn();
}
int main()
{
	Sales_data d1("978-7-121-15535-2", "C++ Primer", 5, 98, 128), d2("978-7-121-15535-1", "Neal Ni", 5, 4, 5);
	Sales_data d3("978-7-121-15535-2", "C++ Primer", 5, 98, 128), d4("978-7-121-15535-3", "C++ Primer Plus",5,80,120);
	vector<Sales_data>vec{d1,d2,d3,d4};
	sort(vec.begin(), vec.end(), compareIsbn);
	for (const auto& e : vec)
		cout << e.isbn() << endl;
	return 0;
}