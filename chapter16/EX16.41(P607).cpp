#include<iostream>
template<typename T>
auto sum(T lhs, T rhs)->decltype(lhs + rhs)
{
	return lhs + rhs;
}
int main()
{
	auto s=sum(1111111111111111111111111111111111111111111111111.0,222222222222222222222222222222222222222222222222222222.0);
}