#include<iostream>
#include<vector>
#include<set>
#include<iterator>
#include<string>
#include<algorithm>
using namespace std;
template <typename T>
void print(const T& s)
{
	for (const auto& e : s)
		cout << e << '\t';
}

int main()
{
	vector<string>vec{ "c++","primer","5th edition" };
	multiset<string>m1{ "neal","ni","hello","world" };
	/*
	copy(vec.begin(), vec.end(), inserter(m1, m1.end()));
	print(m1);
	cout << endl;
	*/
	//copy(vec.begin(), vec.end(), back_inserter(c));illegal, no push_back in multiset 
	/*
	copy(m1.begin(), m1.end(), inserter(vec, vec.end()));
	print(vec);
	*/
	copy(m1.begin(), m1.end(), back_inserter(vec));
	print(vec);
	return 0;
}