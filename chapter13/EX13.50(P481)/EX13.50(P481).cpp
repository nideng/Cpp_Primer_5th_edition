#include"EX13.50(P481).h"
#include<vector>
#include<iostream>
using std::vector;

int main()
{
	vector<String>vec;
	std::cout << vec.capacity() << std::endl;
	String s1("hello"), s2("world"), s3("why"),s4("hi");
	vec.push_back(s1);
	vec.push_back(s2);
	vec.push_back(s3);
	vec.push_back(s4);
}