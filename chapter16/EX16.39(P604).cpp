#include<string>
#include<iostream>
using std::cout; using std::endl;
template<typename T>
int compare(const T& lhs, const T& rhs)
{
	if (lhs < rhs)return -1;
	if (rhs < lhs)return 1;
	return 0;
}
int main()
{
	cout << compare<std::string>("neal", "ni") << endl;
}