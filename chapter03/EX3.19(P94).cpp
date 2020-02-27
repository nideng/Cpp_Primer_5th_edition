#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int>vec1{ 42,42,42,42,42,42,42,42,42,42 };
	vector<int>vec2(10, 42);//the best one,simple and concise
	vector<int>vec3;
	for (unsigned i = 0; i < 10; ++i)
		vec3.push_back(42);
	for (decltype(vec1.size())i = 0; i != 10; ++i)
		cout << vec1[i] << '\t' << vec2[i] << '\t' << vec3[i] << endl;
	return 0;
}