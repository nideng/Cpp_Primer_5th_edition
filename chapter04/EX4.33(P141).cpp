
#include<iostream>
using namespace std;
int main()
{
	int x = 2, y = 3;
	int j = 1 ? (++x, ++y) :( --x, --y);
	cout << j << endl;
}
/*
Because of the most lowest precedence of the comma operator, the expression is same as:
(someValue ? ++x, ++y : --x), --y

If someValue is true, then ++x, and the result is ++y, 
if someValue is false, then --x, and the result is --y. 
so it is also same as:
someValue ? (++x, --y) : (--x, --y);

Even though the result has nothing to do with x, 
the evaluation of someValue does effect the operation on x
*/
