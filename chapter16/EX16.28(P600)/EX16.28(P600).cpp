#include"shared_ptr.h"
#include"unique_ptr.h"
#include<iostream>
using std::cout;
using std::function;

template<typename T>
void f(T* p)
{
	delete p;
}
template<typename T>
function<void(T*)>f1 = f<T>;
int main()
{
	EX16_28_a::shared_ptr<int>ptr(new int(5));
	int* p = new int(1);
	ptr.reset(p, f<int>);
	cout << *ptr << std::endl;
	EX16_28_a::shared_ptr<int>ptr1(new int(2));
	ptr1 = std::move(ptr);
	cout << *ptr1 << std::endl;
	EX16_28_b::unique_ptr<double,decltype(f<double>)*>uptr(new double(3.0),f<double>);

	EX16_28_b::unique_ptr<double>uptr1(new double(2.0));

	EX16_28_b::unique_ptr<double, function<void(double*)>>uptr2(new double(4.0),f<double>);
	return 0;
}