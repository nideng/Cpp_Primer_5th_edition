#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int>vec;
	cout << vec.at(0) << endl;//terminating with uncaught exception of type std::out_of_range
	cout << vec[0] << endl;// Segmentation fault: 11
	cout << vec.front() << endl;
	cout << *(vec.begin()) << endl;
	return 0;
}