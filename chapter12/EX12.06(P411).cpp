#include<iostream>
#include<vector>
using namespace std;
vector<int>* newvector()
{
	return new vector<int>();
}
vector<int>* input(vector<int>*p)
{
	int i;
	while (cin >> i)
		p->push_back(i);
	return p;
}
void output(vector<int>* p)
{
	for (const auto& e : *p)
		cout << e << '\t';
	delete p;
}
int main()
{
	output(input(newvector()));
	return 0;
}