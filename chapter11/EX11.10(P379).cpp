#include<iostream>
#include<vector>
#include<map>
#include<list>
using namespace std;
int main()
{
	map<vector<int>::iterator, int>m;//this is legal
	map<list<int>::iterator, int>m;
	//this can be declared,but can not use,because iterator 
	//in list is bidirectional,no match operator <;
	map<list<int>::iterator, int>m;
}