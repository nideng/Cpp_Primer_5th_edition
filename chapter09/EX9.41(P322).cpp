#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	vector<char>vec{ 'h','e','l','l','o' };
	string s(vec.begin(), vec.end());
	cout << s << endl;
	return 0;

}