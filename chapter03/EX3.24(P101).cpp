//the adjacent elements plus
/*
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int>vec;
	int i;
	while (cin >> i)
		vec.push_back(i);
	if (vec.empty())
	{
		cerr << "Input at least one integer." << endl;
		return -1;
	}
	if (vec.size() %2)
	{
		for (auto it=vec.begin(); it<(vec.end() - 2); it += 2)
			cout << (*it) +*(it+1) << endl;
		cout << *(vec.end()-1) << endl;
	}
	else
		for (auto it=vec.begin(); it<(vec.end()-1); it += 2)
			cout <<(*it)+*(it+1) << endl;
	return 0;
}
*/


#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int>vec;
	int i;
	while (cin >> i)
		vec.push_back(i);
	if (vec.empty())
	{
		cerr << "Input at least one integer." << endl;
		return -1;
	}
	if (vec.size() % 2)
	{
		for (auto it = vec.begin(); it < (vec.begin() + vec.size() / 2); ++it)
			cout << *it + *(vec.begin()+(vec.end()-1-it)) << endl;
		cout << *(vec.begin()+vec.size()/2) << endl;
	}
	else
		for (auto it = vec.begin(); it < (vec.begin()+vec.size()/2) ; ++it)
			cout << *it + *(vec.begin() + (vec.end() - 1 - it)) << endl;
	return 0;
}