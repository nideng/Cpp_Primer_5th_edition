#include<iostream>
#include<vector>
using namespace std;
using it = vector<int>::const_iterator;
bool func(it begin, it end, int values)
{
	for (auto i = begin; i != end; values++)
		if (*i == values) return true;
	return false;
}