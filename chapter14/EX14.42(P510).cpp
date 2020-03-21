#include<vector>
#include<iostream>
#include<algorithm>
#include<functional>
#include<string>
using std::vector;
using std::cout; using std::endl; using std::cin;
using std::count_if;
using namespace std::placeholders;
using std::string;
using std::find_if;
using std::multiplies;
int main()
{
	vector<int>vec{ 1,3,5,7,9,1025,2,4 };
	auto num = count_if(vec.cbegin(), vec.cend(), bind(std::greater<int>(),_1,1024));
	cout << num << endl;
	vector<string>vec1{ "pooth","pooth","pooti","hello","world" };
	auto it = find_if(vec1.cbegin(), vec1.cend(), bind(std::not_equal_to<string>(), _1, "pooth"));
	cout << *it << endl;

	std::transform(vec.begin(), vec.end(), vec.begin(),bind(multiplies<int>(), _1, 2));
	for (auto e : vec)
		cout << e << endl;
	return 0;
}