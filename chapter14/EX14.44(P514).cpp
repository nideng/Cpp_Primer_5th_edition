#include<functional>
#include<iostream>
#include<map>
#include<string>
using std::function;
using std::map;
using std::string;
int add(int i, int j) { return i + j; }
auto mod = [](int i, int j) {return i % j; };
auto multiply = [](int i, int j) {return i * j; };
struct divide {
	int operator()(int denominator, int divisor) {
		return denominator / divisor;
	}
};
function<int(int, int)>f1 = add;
function<int(int, int)>f2 = std::minus<int>();
function<int(int, int)>f3 = multiply;
function<int(int, int)>f4 = divide();
function<int(int, int)>f5 = mod;
map<string, function<int(int, int)>>binops{
	{"+",f1},{"-",f2},{"*",f3},{"/",f4},{"%",f5}
};
int main()
{
	std::cout << "Enter as number operator number" << std::endl;
	int lhs, rhs;
	string op;
	while(std::cin >> lhs >> op >> rhs)
		std::cout << binops[op](lhs, rhs) << std::endl;
	return 0;
}
