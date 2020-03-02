#include"EX7.07(P235).h"
#include<iostream>
using namespace std;
int main()
{
	Sales_data total;
	if (read(cin,total))
	{
		Sales_data trans;
		while (read(cin,trans))
		{
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else
			{
				print(cout,total)<< endl;
				total = trans;
			}
		}
		cout << total << endl;
	}
	else
		cerr << "No data?!" << endl;
	return 0;
}