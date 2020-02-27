//concatenating what is read into one large string
/*
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str,total_str;
	while (cin >> str)
		total_str += str;
	cout << total_str << endl;
	return 0;
}
*/
//separate input strings by a space
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str, total_str;
	while (cin >> str)
		total_str += (str + " ");
	cout << total_str << endl;
	return 0;
}