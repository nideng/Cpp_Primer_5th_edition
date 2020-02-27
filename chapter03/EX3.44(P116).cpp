/*
#include<iostream>
using namespace std;
int main()
{
	int ia[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	using int_array = int[4];
	//range for
	for (int_array& i : ia)
		for (int j : i)
			cout << j << endl;
	return 0;
}
*/

/*
//loop for
//not need type alias
#include<iostream>
using namespace std;
int main()
{
	int ia[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 4; j++)
			cout << ia[i][j] << endl;
	return 0;
}
*/

//pointers

#include<iostream>
using namespace std;
int main()
{
	int ia[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	using int_array = int[4];
	for (int_array* p = ia; p != ia + 3; ++p)
		for (int* q = *p; q != *p + 4; ++q)
			cout << *q << endl;
	return 0;
}

