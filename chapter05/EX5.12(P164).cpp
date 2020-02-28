#include<iostream>
using namespace std;

int main()
{
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0,ffCnt=0,flCnt=0,fiCnt=0;
	char preCh,currCh;
	preCh = '\0';
	while (cin >> currCh)
	{
		switch (tolower(currCh))
		{
		case 'a':
			++aCnt;
			break;
		case 'e':
			++eCnt;
			break;
		case 'i':
			if(tolower(preCh)=='f')
				++fiCnt;
			++iCnt;
			break;
		case 'o':
			++oCnt;
			break;
		case 'u':
			++uCnt;
			break;
		case'f':
			if (tolower(preCh) == 'f')
				++ffCnt;
			break;
		case 'l':
			if (tolower(preCh) == 'f')
				++flCnt;
			break;
		}
		preCh = currCh;
	}
	cout << "The number of vowel a: " << aCnt << endl;
	cout << "The number of vowel e: " << eCnt << endl;
	cout << "The number of vowel i: " << iCnt << endl;
	cout << "The number of vowel o: " << oCnt << endl;
	cout << "The number of vowel u: " << uCnt << endl;
	cout << "The number of vowel ff: " << ffCnt << endl;
	cout << "The number of vowel fi: " << fiCnt << endl;
	cout << "The number of vowel fl: " << flCnt << endl;
	return 0;
}