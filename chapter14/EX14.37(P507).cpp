#include<iostream>
#include<algorithm>
#include<vector>
using std::vector;
class Equal_Value
{
private:
	int number;
public:
	Equal_Value(int i):number(i){}
	bool operator()(int j) { return number==j; }
};
int main() {
	vector<int>vec{ 1,3,5,7,2,4,5 };
    std::replace_if(vec.begin(), vec.end(), Equal_Value(5), 9);
	//for_each(vec.begin(), vec.end(), [](int& s) { if (s == 3) s = 6; });
	for (auto e : vec)
		std::cout << e << std::endl;
	return 0;
}