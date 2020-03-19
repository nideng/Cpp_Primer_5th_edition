#include"EX13.48(P473).h"
#include<vector>
#include<iostream>
using std::vector;

int main()
{
	vector<String>vec;
	String s1("hello"), s2("world"),s3("why");
	vec.push_back(s1);
	vec.push_back(s2);
	vec.push_back(s3);
	for (auto e : vec)
		std::cout << e << std::endl;

}