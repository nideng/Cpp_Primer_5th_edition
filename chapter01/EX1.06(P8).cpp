#include<iostream>
using namespace std;
int main()
{
	int v1, v2;
	cin >> v1 >> v2;
	//expected primary-expression before '<<' token
	//remove the ";"
	cout << "The sum of " << v1
		<< " and " << v2
		<< " is " << v1 + v2 << endl;
	return 0;
}