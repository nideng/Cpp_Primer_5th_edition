#include<iostream>
#include<string>
using namespace std;
string(&func(string(&arr)[10]))[10]
{
	return arr;
}

int main()
{
	string arr1[10] = { "hello","world" };
	func(arr1)[2] = "who";
	for (auto i : func(arr1))
		cout << i << endl;
	return 0;
}