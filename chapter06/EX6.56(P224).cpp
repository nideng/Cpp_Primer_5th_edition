#include<iostream>
#include<vector>
using namespace std;
int func(int a, int b);
using pFunc1 = decltype(func)*;
typedef decltype(func)* pFunc2;
using pFunc3 = int (*)(int a, int b);
using pFunc4 = int(int a, int b);
typedef int(*pFunc5)(int a, int b);
using pFunc6 = decltype(func);
int func1(int a, int b)
{
	return a + b;
}
int func2(int a, int b)
{
	return a - b;
}
int func3(int a, int b)
{
	return a * b;
}
int func4(int a, int b)
{
	return a / b;
}
std::vector<pFunc1> vec1{ func1,func2,func3,func4 };
std::vector<pFunc2> vec2{ func1,func2,func3,func4 };
std::vector<pFunc3> vec3{ func1,func2,func3,func4 };
std::vector<pFunc4*> vec4{ func1,func2,func3,func4 };
std::vector<pFunc5> vec5{ func1,func2,func3,func4 };
std::vector<pFunc6*> vec6{ func1,func2,func3,func4 };

int main()
{
	int a = 2, b = 2;
	for (auto f : vec1)
		cout << f(a, b) << endl;
	return 0;
}