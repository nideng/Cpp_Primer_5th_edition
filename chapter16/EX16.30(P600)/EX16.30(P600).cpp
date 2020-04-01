#include"Blob.h"
#include<iostream>
using std::cout; using std::endl;
int main()
{
	Blob<string>b1{"c++", "primer", "hello", "world"};
	Blob<string>b2 = b1;
	b2 = b1;
	cout << b1[1] << endl;
	return 0;

}