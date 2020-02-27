//The first program, compare which string is larger
/*
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		if (str1 == str2)
			cout << "Two strings are equal." << endl;
		else
			cout << "The larger string is:" << ((str1 > str2) ? str1 : str2) << endl;
	}
	return 0;
}
*/

//The second program, compare which string is longer
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		if (str1.size() == str2.size())
			cout << "Two strings are equal." << endl;
		else
			cout << "The longer strings is: " << ((str1.size() > str2.size()) ? str1 : str2);
	}
	return 0;
}