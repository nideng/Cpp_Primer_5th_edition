#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
void elimDups(vector<string>& s)
{
	sort(s.begin(), s.end());
	auto it = unique(s.begin(), s.end());
	s.erase(it, s.end());
}
int main()
{
	string word;
	vector<string>vec;
	while (cin >> word)
		vec.push_back(word);
	elimDups(vec);
	for (const auto& e : vec)
		cout << e << endl;
	return 0;
}
/*
//  1.No matter what elements you add or remove (unless you add
//  a duplicate, which is not allowed in a set), it will always
//  be ordered.
//  2.A vector has exactly and only the ordering you explicitly
//  give it. Items in a vector are where you put them. If you put
//  them in out of order, then they're out of order; you now need
//  to sort the container to put them back in order.
//  3.However, if you are constantly inserting and removing items
//  from the container, vector will run into many issues.
//  4.The time it takes to insert an item into a vector is proportional
//  to the number of items already in the vector. The time it takes
//  to insert an item into a set is proportional to the log of the
//  number of items. If the number of items is large, that's a huge
//  difference. Log(100, 000) is 17; that's a major speed improvement.
//  The same goes for removal.


*/