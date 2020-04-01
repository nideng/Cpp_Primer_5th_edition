#include<vector>
#include<iostream>
using std::vector;
using std::cout; using std::endl;

template<typename Container>
void print(const Container& c)
{
	for (auto it = c.begin(); it != c.end(); ++it)
		cout << *it << endl;
}

int main()
{
	vector<int>vec = { 1,2,3,4,5 };
	print(vec);
	return 0;
}