#include<iostream>
#include<string>
#include<iterator>
using namespace std;
int main()
{
	string s1("hello"), s2("world");
	char* ch = new char[(s1 + s2).size()+1];
	for (size_t i = 0; i <= (s1 + s2).size(); ++i)
		ch[i] = (s1 + s2)[i];
	cout << ch << endl;
	delete []ch;
}