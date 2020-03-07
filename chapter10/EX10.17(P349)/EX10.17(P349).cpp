#include<iostream>
#include"EX10.17(P349).h"
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	Sales_data d1("978-7-121-15535-2", "C++ Primer", 5, 98, 128), d2("978-7-121-15535-1", "Neal Ni", 5, 4, 5);
	Sales_data d3("978-7-121-15535-2", "C++ Primer", 5, 98, 128), d4("978-7-121-15535-3", "C++ Primer Plus", 5, 80, 120);
	vector<Sales_data>vec{ d1,d2,d3,d4 };
	sort(vec.begin(), vec.end(), [](const Sales_data& vec1, const Sales_data& vec2) {return vec1.isbn() < vec2.isbn(); });
	for (const auto& e : vec)
		cout << e.isbn() << endl;
	return 0;
}