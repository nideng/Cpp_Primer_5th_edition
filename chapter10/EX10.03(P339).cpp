#include<iostream>
#include<numeric>
#include<vector>
using namespace std;

int main()
{
	vector<int>vec{ 1,2,3,4,5,6,7,8,9 };
	cout << "The sum is: " << accumulate(vec.cbegin(), vec.cend(), 0) << endl;
	return 0;
}