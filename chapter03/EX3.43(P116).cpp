//range for
/*
#include<iostream>
#include<iterator>
using namespace std;
int main()
{
	int ia[3][4] = { {0,1,2,3},{4,5,6,7},{8,9,10,11} };
	//range for
	for (int (&row)[4]:ia)
		for (int col:row)
			cout << col << endl;
	return 0;
}
*/

//loop for
/*
#include<iostream>
using namespace std;

int main()
{
	int ia[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	for (size_t i = 0; i < 3; ++i)
		for (size_t j = 0; j < 4; ++j)
			cout << ia[i][j] << endl;
	return 0;
}
*/

//pionter
#include<iostream>
#include<iterator>
using namespace std;

int main()
{
	int ia[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	for (int(*i)[4] = ia; i != (ia + 3); ++i)
		for (int* j = *i; j != *i + 4; ++j)
			cout << *j << endl;
	return 0;
}
