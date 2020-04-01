#include<iostream>
using std::cout; using std::endl;
namespace EX16_06
{
	template<typename T,unsigned N>
	const T* begin(const T(&arr)[N])
	{
		return arr;
	}
	template<typename T,unsigned N>
	const T* end(const T(&arr)[N])
	{
		return arr + N;
	}
}
int main()
{
	int arr1[5] = { 1,2,3,4,5 };
	cout << *EX16_06::begin(arr1) << endl;
	cout << *EX16_06::end(arr1) << endl;

}