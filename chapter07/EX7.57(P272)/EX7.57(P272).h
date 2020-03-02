#ifndef ACCOUNT_H
#define ACCOUNT_H
#include<string>
using namespace std;
class Account 
{
private:
	string owner;
	double amount;
	static double interestRate;
	static constexpr double defaulRate = 4.2;
	static double initRate() { return defaulRate; }
public:
	void caculate() { amount += amount * interestRate; }
	static double rate() { return interestRate; }
	static void rate(double);
};
void Account::rate(double i)
{
	interestRate = i;
}
double Account::interestRate = initRate();
#endif // !ACCOUNT_H
