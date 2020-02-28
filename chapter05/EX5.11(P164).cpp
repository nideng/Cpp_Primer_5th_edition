#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0,spaceCnt=0,tabCnt=0,newlineCnt=0;
	char ch;
	while (cin>>noskipws>>ch)//noskipws is necessary
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
		case ' ':
			++spaceCnt;
			break;
		case '\t':
			++tabCnt;
			break;
		case '\n':
			++newlineCnt;
			break;
		}
	}
	cout << "The number of vowel a: " << aCnt << endl;
	cout << "The number of vowel e: " << eCnt << endl;
	cout << "The number of vowel i: " << iCnt << endl;
	cout << "The number of vowel o: " << oCnt << endl;
	cout << "The number of vowel u: " << uCnt << endl;
	cout << "The number of space: " << spaceCnt << endl;
	cout << "The number of tab: " << tabCnt << endl;
	cout << "The number of newline: " << newlineCnt << endl;
	return 0;
}