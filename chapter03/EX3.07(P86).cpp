#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str("an example string");
	for (char c : str)//should change to for(char& c:str)
		c = 'X';
	cout << str << endl;
	return 0;
}
/*
The point here is using reference to mutate a string. 
If changed to something like below, c would become a char rather than char&. 
In such case, c is a copy of each character of string str, thus the assignment c = 'X' won't mutate str.
As a result, after this for range statement, nothing changes.
/*