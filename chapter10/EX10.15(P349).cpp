#include<iostream>
using namespace std;
int main()
{
	int i = 2;
	auto sum = [i](int j) {return i + j; };

}