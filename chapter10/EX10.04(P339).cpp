#include<iostream>
#include<numeric>
#include<vector>
using namespace std;

int main()
{
	vector < double > vec{ 1.6,2.0,3.0,4,5,6,7,8,9 };
	cout << "The sum is: " << accumulate(vec.cbegin(), vec.cend(), 0) << endl;
	return 0;
}
//The result is 45 instead of 45.6;
// The reason is std::accumulate is a template function. The third parameter is _Tp __init
// When "0" , an integer, had been specified here, the compiler deduced _Tp as
// interger.As a result , when the following statments were being excuted :
//  for (; __first != __last; ++__first)
//	__init = __init + *__first;
//  return __init;
// all calculation would be converted to integer.