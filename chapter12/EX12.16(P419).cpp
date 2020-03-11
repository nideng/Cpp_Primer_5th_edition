#include<iostream>
#include<memory>
using namespace std;
int main()
{
	unique_ptr<double>p1(new double(2.0));
	unique_ptr<double>p2(p1);
	//Call to implicitly-deleted copy constructor
	return 0;
}