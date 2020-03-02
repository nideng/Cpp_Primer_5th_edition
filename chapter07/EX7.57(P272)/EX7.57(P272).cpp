#include<iostream>
#include"EX7.57(P272).h"
#include<string>
using namespace std;

int main()
{
	double i = Account::rate();
	cout << i << endl;
	Account j;
	cout << j.rate() << endl;
	Account::rate(20.0);
	double k = Account::rate();
	cout << k << endl;
	cout << j.rate() << endl;
	return 0;
}