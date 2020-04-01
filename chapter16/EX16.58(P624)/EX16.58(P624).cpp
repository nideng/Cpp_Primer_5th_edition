#include"StrVec.h"
#include"Vec.h"
#include<iostream>
int main()
{
	Vec<std::string> v;
	v.emplace_back(10, 'c');
	for (auto e : v)
		std::cout << e << std::endl;
	StrVec v1;
	v1.emplace_back("hello");
	for (auto e : v1)
		std::cout << e << std::endl;
	return 0;
}