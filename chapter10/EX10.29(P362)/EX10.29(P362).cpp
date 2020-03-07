#include<iostream>
#include<vector>
#include<fstream>
#include<iterator>
using namespace std;
int main()
{
	vector<string>vec1;
	ifstream in("EX10.29(P362).txt");
	istream_iterator<string>str_iter(in),eof;
	while (str_iter!=eof)
		vec1.push_back(*str_iter++);
	ostream_iterator<string>str_oter(cout,"\n");
	for (auto e : vec1)
		*str_oter++ = e;
	return 0;;
}