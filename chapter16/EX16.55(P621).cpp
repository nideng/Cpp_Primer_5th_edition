#include<iostream>
#include<string>
using std::ostream;
using std::string;

template<typename T, typename...Args>
ostream& print(ostream& os, const T& t, const Args&...rest)
{
	os << t << ", ";
	return print(os, rest...);
}
template<typename T>
ostream& print(ostream& os, const T& t)
{
	return os << t;
}
int main()
{
	int i = 0;
	double d = 3.14;
	string s = "hello";
	const char* p = "neal";
	print(std::cout, i, d, s, p); //no matching function for call
	std::cout << std::endl;
	print(std::cout, i, d);
	std::cout << std::endl;
	print(std::cout, i);
}