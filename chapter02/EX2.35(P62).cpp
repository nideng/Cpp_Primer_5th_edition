#include<iostream>
using namespace std;
int main()
{
	const int i = 42;
	auto j = i;
	const auto& k = i;
	auto* p = &i;
	const auto j2 = i, & k2 = i;
}
//j is int. k is const int&. p is const int *. j2 is const int. k2 is const int&.