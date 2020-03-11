#include<iostream>
#include<memory>
#include<vector>
using namespace std;
#include<iostream>
#include<vector>
using namespace std;

shared_ptr<vector<int>> newvector()
{
	return make_shared<vector<int>>();
}
shared_ptr<vector<int>> input(shared_ptr<vector<int>>p)
{
	int i;
	while (cin >> i)
		p->push_back(i);
	return p;
}
void output(shared_ptr<vector<int>> p)
{
	for (const auto& e : *p)
		cout << e << '\t';
}
int main()
{
	output(input(newvector()));
	return 0;
}