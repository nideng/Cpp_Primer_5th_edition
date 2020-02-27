//(a)copy an array to another array
/*
#include<iostream>
using namespace std;
int main()
{
	int array1[10], array2[10];
	for (size_t i = 0; i < 10; ++i)
	{
		array1[i] = i;
		cout << array1[i] << endl;
	}
	for (size_t i = 0; i < 10; ++i)
	{
		array2[i] = array1[i];//copy
		cout << array2[i] << endl;
	}
	return 0;
}
*/

//(b)copy a vector;
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int>vec1,vec2;
	for (decltype(vec1.size())i=0;i<10;++i)
	{
		vec1.push_back(i);
		cout << vec1[i] << endl;
	}
	vec2 = vec1;
	for (auto e:vec2)
	{
		cout << e << endl;
	}
	return 0;
}