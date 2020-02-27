#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str("an example string");
	for (auto &s : str)
		s = 'X';
	cout << str << endl;
}