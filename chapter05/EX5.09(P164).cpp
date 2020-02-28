#include<iostream>
using namespace std;
int main()
{
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	char ch;
	while (cin>>ch)
	{
		if (ch == 'a')
			++aCnt;
		else if (ch == 'e')
			++eCnt;
		else if (ch == 'i')
			++iCnt;
		else if (ch == 'o')
			++oCnt;
		else if (ch == 'u')
			++uCnt;
	}
	cout << "The number of vowel a: " << aCnt << endl;
	cout << "The number of vowel e: " << eCnt << endl;
	cout << "The number of vowel i: " << iCnt << endl;
	cout << "The number of vowel o: " << oCnt << endl;
	cout << "The number of vowel u: " << uCnt << endl;
	return 0;
}