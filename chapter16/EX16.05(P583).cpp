#include<iostream>
#include<string>
using std::string;
using std::cout; using std::endl;
template<typename T,size_t n>
void print(const T(&arr)[n])
{
	for (auto elem : arr)
		cout << elem << endl;
}
int main()
{
	string arr1[3] = { "c++","primer","5th" };
	print(arr1);
	int arr2[] = { 1,2,3,4,5,6};
	print(arr2);
	return 0;
}