/*
three identical numbers;
*/

//Example:
#include<iostream>
using namespace std;
class numbered
{
public:
	numbered() { mysn = num++; }
	unsigned mysn;
public:
	static unsigned num;
};
unsigned numbered::num = 0;
void f(numbered s) { cout << s.mysn << endl; }
int main()
{
	numbered a, b = a, c = b;
	f(a);
	f(b);
	f(c);
	return 0;
}