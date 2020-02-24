#include<iostream>

int main()
{
	std::cout << "/*";
	std::cout << "*/";
	//std::cout <</*"*/"*/这句编译无法通过，改为如下：
	std::cout <</*"*/"*/";
	std::cout <</*"*/"/*"/*"*/;
	return 0;
}