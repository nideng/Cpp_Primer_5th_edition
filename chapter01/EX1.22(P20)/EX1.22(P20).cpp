#include<iostream>
#include"EX1.22(P20).h"

int main()
{
	Sales_item item1, item2;
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