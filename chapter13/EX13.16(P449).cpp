/*
Yes, the output will change. Because no copy operation happens 
within function f. Thus, the three Output are the same.
*/
#include<iostream>
using namespace std;
class numbered
{
public:
	numbered() { mysn = num++; }
	numbered(const numbered&) { mysn = num++; }
	unsigned mysn;
public:
	static unsigned num;
};
unsigned numbered::num = 0;
void f(const numbered &s) { cout << s.mysn << endl; }
int main()
{
	numbered a, b = a, c = b;
	f(a);
	f(b);
	f(c);
	return 0;
}