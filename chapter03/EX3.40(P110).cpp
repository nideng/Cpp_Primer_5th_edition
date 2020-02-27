#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;
const char str1[] = "Neal";
const char str2[] = "Ni";
int main()
{
	char* str3=new char[strlen(str1)+strlen(" ")+strlen(str2)+1];
	strcpy(str3,str1);
	strcat(str3, " ");
	strcat(str3, str2);
	cout << str3 << endl;
	delete[] str3;
	return 0;
}