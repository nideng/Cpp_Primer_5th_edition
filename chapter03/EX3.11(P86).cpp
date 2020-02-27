#include<iostream>
#include<string>
using namespace std;
int main()
{
	const string s = "keep out!";
	for (auto& c : s)
	{

	}
}
/*
The type of c is const char&
Depending on the code,in the loop, if the value of c is not changed, the code legal.
*/