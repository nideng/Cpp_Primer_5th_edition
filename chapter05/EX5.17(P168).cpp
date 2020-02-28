#include<iostream>
#include<vector>
using namespace std;
bool is_prefix(const vector<int>& vec1, const vector<int>& vec2)
{
	if (vec1.size() > vec2.size())
		is_prefix(vec2, vec1);
	for (auto i = vec1.begin(), j = vec2.begin(); i != vec1.end(); ++i, ++j)
	{
		if (*i != *j)
			return false;
	}
	return true;
}

int main()
{
	vector<int>vec1{ 0,1,1,2 };
	vector<int>vec2{ 0,1,1,2,3,5,8 };
	cout << (is_prefix(vec1, vec2)?"yes":"no") << endl;
	return 0;
}