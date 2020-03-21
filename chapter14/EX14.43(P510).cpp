#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
using std::vector;
int main()
{
	vector<int>vec{ 1,3,5,7,9 };
	auto i = std::any_of(vec.cbegin(), vec.cend(), [](int i) {return (!(i % 2)); });
	std::cout << i << std::endl;
	//a better method;
	int input;
	std::cin >> input;
	std::modulus<int> mod;
	auto predicator = [&](int i) { return 0 == mod(i,input); };
	auto is_divisible = std::any_of(vec.begin(), vec.end(), predicator);
	std::cout << (is_divisible ? "Yes!" : "No!") << std::endl;
	return 0;
}