#include<vector>
#include<iostream>
using std::vector;
using std::cout; using std::endl;
template<typename Container>
void print(const Container&vec)
{
	for (typename Container::size_type i = 0; i != vec.size(); ++i)
		cout << vec.at(i) << endl;
}
int main()
{
	vector<int>vec = { 1,2,3,4,5 };
	print(vec);
}