#include<iostream>
#include"EX1.24(P21).h"
using std::cout;
using std::cin;
using std::endl;
int main()
{
	int Cnt = 1;
	Sales_item item1;
	if (cin >> item1)
	{
		Sales_item item2;
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