#include"Sales_data.h"
#include<unordered_set>
#include<iostream>
namespace std
{
	template<>
	class hash<Sales_data>
	{
	public:
		typedef size_t result_type;
		typedef Sales_data argument_type;
		size_t operator()(const Sales_data& s)const;
	};
	size_t
		hash<Sales_data>::operator()(const Sales_data& s)const
	{
		return hash<string>()(s.bookNo) ^
			hash<unsigned>()(s.units_sold) ^
			hash<double>()(s.revenue);
	}
}
int main()
{
	std::unordered_multiset<Sales_data>SDset;
	Sales_data item;
	while (std::cin >> item) {
		SDset.insert(item);
	}
	for (auto e : SDset)
		std::cout << e << std::endl;

}