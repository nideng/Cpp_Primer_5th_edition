//(1)
/*
#include<iostream>
#include<string>
using namespace std;
using stringarr = string(&)[10];
stringarr func(stringarr arr)
{
	return arr;
}
int main()
{
	string arr1[10] = { "hello","world" };
	func(arr1)[2] = "who";
	for (auto i : arr1)
		cout << i << endl;
	return 0;
}
*/
//(2)
/*
#include<iostream>
#include<string>
using namespace std;
auto func(string (&arr)[10])->string (&)[10]
{
	return arr;
}
int main()
{
	string arr1[10] = { "hello","world" };
	func(arr1)[2] = "who";
	for (auto i : arr1)
		cout << i << endl;
	return 0;
}
*/

//(3)
#include<iostream>
#include<string>
using namespace std;
string odd[10] = {};
decltype(odd)& func(string (&arr)[10])//"&"is needed
{
	return arr;
}
int main()
{
	string arr1[10] = { "hello","world" };
	func(arr1)[2] = "who";
	for (auto i : arr1)
		cout << i << endl;
	return 0;
}