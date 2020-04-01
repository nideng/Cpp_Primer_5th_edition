/*
legal.As shown below, only type that support this + 0 operation can be passed.
*/
#include<vector>
using std::vector;
class f {
	friend f operator+(f lhs, int)
	{
		return lhs;
	}
};
template<typename It>
auto fcn3(It beg, It end)->decltype(*beg + 0)
{
	return *beg;
}
int main()
{
	vector<f>vec{f(),f()};
	f f1 = fcn3(vec.begin(), vec.end());
	return 0;
}