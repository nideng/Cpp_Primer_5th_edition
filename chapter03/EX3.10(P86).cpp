
#include<iostream>
#include<string>
using namespace std;
int main()
{
	cout << "Please enter a string including a punctuation." << endl;
	string str;
	while (getline(cin, str))
	{
		for (auto i : str)
		{
			if (!ispunct(i))//removing thr punctuation
				cout << i;
		}
	}
	return 0;
}