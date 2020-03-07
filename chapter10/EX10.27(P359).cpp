#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<string>
using namespace std;

int main()
{
	vector<string>vec1{ "the","quick","red","fox","jumps","over","the","slow","red","turtle" };
	sort(vec1.begin(), vec1.end());//This is necessary ,or the function unique_copy has no effect
	list<string>l1;
	unique_copy(vec1.begin(), vec1.end(), back_inserter(l1));
	for (auto e : l1)
		cout << e << endl;
	return 0;
}