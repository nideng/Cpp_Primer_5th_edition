#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int>v1;
	cout << "size" << '\t' << "capacity" << endl;
	cout << v1.size() << '\t' << v1.capacity() << endl;
	for (int i = 0; i < 20; i++)
	{
		v1.push_back(i);
		cout << v1.size() << '\t' << v1.capacity() << endl;
	}
	return 0;
}