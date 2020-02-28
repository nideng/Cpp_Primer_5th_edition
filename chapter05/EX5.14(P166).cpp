#include<iostream>
#include<string>
using namespace std;
int main()
{
	string preStr, currStr,maxStr;
	unsigned maxCnt = 1,currCnt=1;
	while (cin >> currStr)
	{
		if (currStr == preStr)
		{
			++currCnt;
			if (currCnt > maxCnt)
			{
				maxCnt = currCnt;
				maxStr = currStr;
			}
		}
		else
			currCnt = 1;
		preStr = currStr;
	}
	if (maxCnt == 1)
		cout << "There is no duplicated string." << endl;
	else
		cout << maxStr <<" occurred " << maxCnt <<" times."<< endl;
	return 0;
}

