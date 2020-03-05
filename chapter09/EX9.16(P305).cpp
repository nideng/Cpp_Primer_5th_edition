#include<iostream>
#include<vector>
#include<list>
using namespace std;
int main()
{
	vector<int>vec1{ 1,3,5,7,9,12 };
	list<int>list1{ 1,3,5,7,9,12 };
	list<int>list2{ 1,3,5,7 };
	vector<int>vec2(list1.begin(), list1.end());
	vector<int>vec3(list2.begin(), list2.end());

	if (vec1 == vec2)
		cout << "vec1==vec2" << endl;
	if (vec1 == vec3)
		cout << "vec1==vec3" << endl;

}