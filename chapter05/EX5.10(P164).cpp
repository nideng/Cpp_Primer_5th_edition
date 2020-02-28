#include<iostream>

using namespace std;
int main()
{
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	char ch;
	while (cin >> ch)
	{
		switch (tolower(ch))
		{
		case 'a':
			++aCnt;
			break;
		case 'e':
			++eCnt;
			break;
		case 'i':
			++iCnt;
			break;
		case 'o':
			++oCnt;
			break;
		case 'u':
			++uCnt;
			break;
		}
	}
	cout << "The number of vowel a: " << aCnt << endl;
	cout << "The number of vowel e: " << eCnt << endl;
	cout << "The number of vowel i: " << iCnt << endl;
	cout << "The number of vowel o: " << oCnt << endl;
	cout << "The number of vowel u: " << uCnt << endl;
	return 0;
}