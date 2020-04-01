#include<vector>
#include<string>
#include<list>
#include<iostream>
using std::list;
using std::vector;
using std::string;
using std::cout; using std::endl;
namespace EX16_04
{
	template<typename T, typename U>
	T find(const T & begin, const T & end, const U & sought)
	{
		for (auto it = begin; it != end; ++it)
		{
			if (*it == sought)
				return it;
		}
		return end;
	}
}
int main()
{
	vector<int>vec{ 1,2,3,4,5,6 };
	auto it = EX16_04::find(vec.begin(), vec.end(), 3);
	cout << *it << endl;
	list<string>ls{ "c++","primer","hello","world" };
	auto it2 = EX16_04::find(ls.begin(), ls.end(), "hello");
	cout << *it2 << endl;
}