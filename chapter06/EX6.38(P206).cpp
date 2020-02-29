#include<iostream>
using namespace std;
int odd[] = {1,3,5,7,9};
int even[] = { 0,2,4,6,8 };
;decltype(odd)& arrptr(int i)
{
	return (i % 2) ? odd : even;
}
int main()
{
	int i = 1;
	for (auto e : arrptr(i))
		cout << e << endl;
	return 0;
}