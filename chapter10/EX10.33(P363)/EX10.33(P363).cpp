#include<fstream>
#include<iostream>
#include<iterator>
#include<algorithm>
using namespace std;
int main()
{
	ifstream input("EX10.33(P363).txt");
	istream_iterator<int>in(input), eof;
	ofstream output1("EX10.33(P363)_ODD.txt"),output2("EX10.33(P363)_EVEN.txt");
	ostream_iterator<int>out1(output1, " "),out2(output2,"\n");
	for_each(in, eof,
		[&out1, &out2](const int i) {*((i % 2) ? out1 : out2)++ = i; });
	return 0;
}