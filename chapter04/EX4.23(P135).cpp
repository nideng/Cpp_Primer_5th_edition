

#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s = "word";
	string p1 = s + s[s.size() - 1] = 's' ? "" : "s";//Operator Precedence: = < ?: < == < + 
	//correct it
	string p2 = s + (s[s.size() - 1] == 's' ? "" : "s");
	cout << p1 << endl;
	cout << p2 << endl;
	return 0;
}