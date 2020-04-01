#include"EX16.16(P592).h"
#include<iostream>
int main()
{
	Vec<int>v1{ 1,2,3,4,5,6,7,8 };
	Vec<std::string>v2{ "c++","primer" };
	for (auto e : v1)
		std::cout << e << " ";
	std::cout << std::endl;
	for (auto e : v2)
		std::cout << e << " ";
}