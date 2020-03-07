#include<iostream>
#include<list>
#include<iterator>
#include<algorithm>
using namespace std;
void elimDups(list<string>& words)
{
	words.sort();
	words.unique();
}
int main()
{
	list<string>li{ "the","quick","red","fox","jumps","over","the","slow","red","turtle" };
	elimDups(li);
	for (const auto &e : li)
		cout << e << endl;
	return 0;
}