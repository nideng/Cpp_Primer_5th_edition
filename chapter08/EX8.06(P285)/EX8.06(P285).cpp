//At present, I don't know how to pass arguments to main

#include"EX8.06(P285).h"
#include<fstream>
#include<iostream>
using namespace std;
int main()
{
	ifstream input("book.txt");
	Sales_data total(input);
	if (!total.isbn().empty())
	{
		Sales_data trans;
		while (read(input,trans))
		{
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