#include<iostream>
#include<string>
using namespace std;
string sa[10];//all elements are empty strings;
int ia[10];//all elempents are 0;
int main()
{
	string sa2[10];//all elements are empty strings;
	int ia2[10];//all elements are undefined;
	for (int i = 0; i < 10; i++)
		cout << sa[i] << '\t' << ia[i] << '\t' << sa2[i] << '\t' << ia2[i] << endl;
	return 0;
}