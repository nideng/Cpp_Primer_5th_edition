#include<iostream>
#include<string>
using std::string;
using std::cout; using std::endl;
namespace EX16_07
{
	template<typename T, size_t N>
	constexpr size_t size(const T(&arr)[N])
	{
		return N;
	}
}
int main()
{
	int arr[] = { 1,2,3,4,5 };
	cout << EX16_07::size(arr) << endl;
	string arr1[] = { "hello","world" };
	cout << EX16_07::size(arr1) << endl;
	return 0;
}