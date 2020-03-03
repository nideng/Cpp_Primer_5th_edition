
#include"EX8.07(P287).h"
#include<fstream>
#include<iostream>
using namespace std;
int main()
{
	ifstream input("EX8.07(P287).txt");
	ofstream output("EX8.07(P287)_COPY.txt");
	Sales_data total(input);
	if (!total.isbn().empty())
	{
		Sales_data trans;
		while (read(input, trans))
		{
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else
			{
				print(output, total) << endl;
				total = trans;
			}
		}
		print(output,total)<<endl;
	}
	else
		cerr << "No data?!" << endl;
	return 0;
}