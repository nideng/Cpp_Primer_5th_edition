/*
#include<iostream>
#include"EX2.42(P68).h"

int main()
{
	Sales_data book;
	std::cin >> book;
	std::cout << book << std::endl;
	return 0;
}
*/
/*
#include<iostream>
#include"EX2.40(P65).h"
int main()
{
	Sales_data item1, item2;
	std::cin >> item1 >> item2;
	if (item1.isbn() == item2.isbn())
	{
		std::cout << item1 + item2 << std::endl;
		return 0;
	}
	else
	{
		std::cerr << "Data must refer to same ISBN"
			<< std::endl;
		return -1;
	}
}
*/
/*
#include<iostream>
#include"EX2.40(P65).h"
using std::cout;
using std::cin;
using std::endl;
int main()
{
	int Cnt = 1;
	Sales_data item1;
	if (cin >> item1)
	{
		Sales_data item2;
		while (cin >> item2)
		{
			if (item1.isbn() == item2.isbn())
				++Cnt;
			else
			{
				cout << item1 << " occurs " << Cnt << " times" << endl;
				//这种统计方式要求同一ISBN的记录必须聚在一起输入，待改进
				item1 = item2;
				Cnt = 1;
			}
		}
		cout << item1 << " occurs " << Cnt << " times" << endl;
	}
	return 0;
}
*/

#include<iostream>
#include"EX2.40(P65).h"

int main()
{
	Sales_data item1, item2;
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
