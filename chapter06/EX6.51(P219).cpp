#include<iostream>
using namespace std;
void f()
{
	cout << "call the function of f()" << endl;
}
void f(int)
{
	cout << "call the function if f(int)" << endl;
}
void f(int, int)
{
	cout << "call the function of f(int,int)" << endl;
}
void f(double, double = 3.14)
{
	cout << "call the function of f(doubel,double)" << endl;
}
int main()
{
	//f(2.56, 42);
	f(42);
	f(42, 0);
	f(2.56, 3.14);
}