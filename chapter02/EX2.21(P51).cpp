#include<iostream>
using namespace std;
int main()
{
	int i = 0;
	double* dp = &i;//illegal, cannot initialize a variable of type 'double *' with an rvalue of type 'int *'
	int* ip = i;// illegal, cannot initialize a variable of type 'int *' with an value of type 'int'
	int* p = &i;//legal
}