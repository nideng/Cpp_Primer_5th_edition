#include<iostream>
#include<iterator>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	istream_iterator<int>in(cin),eof;
	vector<int>vec;
	copy(in, eof, back_inserter(vec));
	sort(vec.begin(), vec.end());
	ostream_iterator<int>out(cout," ");
	copy(vec.begin(),vec.end(),out);
	return 0;
}