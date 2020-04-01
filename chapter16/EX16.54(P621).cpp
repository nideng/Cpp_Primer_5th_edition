#include<iostream>
#include<string>
using std::ostream;
using std::string;
template<typename T>
ostream& print(ostream& os, const T& t)
{
	return os << t;
}
template<typename T, typename...Args>
ostream& print(ostream& os, const T& t, const Args&...rest)
{
	os << t << ", ";
	return print(os, rest...);
}
class bar
{
};
int main()
{
	bar b;
	print(std::cout, b);//It didn't  compile.
}