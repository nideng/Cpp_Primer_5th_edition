#include<iostream>
#include<vector>
#include<iterator>
using namespace std;

bool compare(const int* pbegin1, const int* pbegin2,const int* pend1,const int* pend2)
{
	if ((pend1 - pbegin1) != (pend2 - pbegin2))
		return false;
	else
	{
		for (auto i = pbegin1, j = pbegin2; (i != pend1) & (j != pend2); ++i, ++j)
		{
			if (*i != *j)
				return false;
		}
	}
	return true;
}
int main()
{
	int arr1[5] = { 1,2,3,4,5 };
	int arr2[5] = { 1,2,3,3,5 };
	if(compare(begin(arr1),begin(arr2),end(arr1),end(arr2)))
		cout<<"The two arrays are equal"<<endl;
	else
		cout<<"The two arrays are not equal"<<endl;
	cout << "===============================" << endl;
	vector<int>vec1(10, 0);
	vector<int>vec2(9, 0);
	if (vec1 == vec2)
		cout << "The two vectors are equal" << endl;
	else
		cout << "The two vectors are not equal" << endl;
	return 0;
}