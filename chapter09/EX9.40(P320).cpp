#include<iostream>
#include<vector>
#include<string>
using namespace std;
void func(vector<string>& vec)
{
	cout << "size" << '\t' << "capacity" << endl;
	cout << vec.size() << '\t' << vec.capacity()<< endl;
	vec.resize(vec.size() + vec.size() / 2);
	cout << "After resize:" << endl;
	cout << vec.size() << '\t' << vec.capacity() << endl;
	cout << "=====================" << endl;
}
int main()
{
	vector<string>svec;
	svec.reserve(1024);
	func(svec);
	for (int i = 0; i < 256; i++)
		svec.push_back("hello");
	func(svec);
	svec.clear();
	for (int i = 0; i < 512; i++)
		svec.push_back("hello");
	func(svec);
	svec.clear();
	for (int i = 0; i < 1000; i++)
		svec.push_back("hello");
	func(svec);
	svec.clear();
	for (int i = 0; i < 1048; i++)
		svec.push_back("hello");
	func(svec);
	svec.clear();
	for (int i = 0; i < 2048; i++)
		svec.push_back("hello");
	func(svec);
	return 0;
}