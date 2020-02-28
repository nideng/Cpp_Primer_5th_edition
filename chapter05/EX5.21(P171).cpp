#include<iostream>
#include<string>
using namespace std;

int main()
{
	string preStr, currStr;
	bool i = false;
	while (cin >> currStr)
	{
		if (currStr == preStr&&isupper(currStr[0]))
		{
			i = true;
			break;
		}
		preStr = currStr;
	}
	if (i)
		cout << "The duplicated word is: " << currStr << endl;
	else
		cout << "No duplicated word" << endl;
	return 0;
}