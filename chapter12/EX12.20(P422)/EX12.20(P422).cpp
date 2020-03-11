#include"EX12.20(P422).h"
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
int main()
{
	StrBlob s;
	ifstream input("EX12.20(P422).txt");
	string line, word;
	while (getline(input, line))
	{
		istringstream in(line);
		while (in >> word)
			s.push_back(word);
	}
	StrBlobPtr p1 = s.begin();
	for (;; p1.incr())
	{
		cout << p1.deref() << endl;
	}
	return 0;
}