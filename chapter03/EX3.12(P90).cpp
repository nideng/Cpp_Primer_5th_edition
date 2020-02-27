#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	vector<vector<int>>ivec;//legal,vectors;
	//vector<string>svec = ivec;//initial with a different type
	vector<string>svec(10, "null");//legal,vector have 10 strings,"null"
}