#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int>vec1{ 1,3,5,7,9,12 };
	vector<int>vec2{ 1,3,5,7,9,12 };
	vector<int>vec3{ 1,3,5,7 };
	if (vec1 == vec2)
		cout << "vec1==vec2" << endl;
	if (vec1 == vec3)
		cout << "vec1==vec3" << endl;
	return 0;
}