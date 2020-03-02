#include"EX7.13(P239).h"
#include<iostream>
using namespace std;
int main()
{
	Sales_data total(cin);
	if (!total.isbn().empty())
	{
		Sales_data trans;
		while (cin)
		{
			Sales_data tans(cin);
			if (!cin) break;
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else
			{
				print(cout, total) << endl;
				total = trans;
			}
		}
		cout << total << endl;
	}
	else
		cerr << "No data?!" << endl;
	return 0;
}