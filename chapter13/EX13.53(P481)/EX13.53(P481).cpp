/*
There is no reason (in most cases) to create std::string 
dynamically, and it comes at the cost of an additional memory 
allocation and the pain of having to manage the lifetime. 
Given that there is no advantage and some disadvantages,
*/

//this code still have some problems:when using move constructor,
//how to deal wiht *use;
#include"EX13.53(P481).h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector<HasPtr>vec;
	HasPtr h1("hello");
	HasPtr h2("world"); 
	HasPtr h3("c++");
	HasPtr h4("primer");
	vec.push_back(h1);
	vec.push_back(h2);
	vec.push_back(h3);
	vec.push_back(h4);
	auto h5 = std::move(h1);
	return 0;
}
