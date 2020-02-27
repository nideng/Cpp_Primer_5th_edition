//the adjacent elements plus
/*
#include<iostream>
#include<vector>
using namespace std;
using T = vector<int>::size_type;
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
		for (T it=0; it<(vec.size() - 2); it += 2)
			cout << vec[it] +vec[it+1] << endl;
		cout << vec[vec.size()-1] << endl;
	}
	else
		for (T it=0; it<(vec.size()-1); it+=2)
			cout <<vec[it]+vec[it+1] << endl;
	return 0;
}
*/


#include<iostream>
#include<vector>
using namespace std;
using T = vector<int>::size_type;
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
		for (T it = 0; it <  (vec.size()-1) / 2; ++it)
			cout << vec[it] + vec[vec.size()-1-it] << endl;
		cout << vec[vec.size()/2] << endl;
	}
	else
		for (T it=0; it <vec.size()/2; ++it)
			cout << vec[it]+vec[vec.size()-1-it] << endl;
	return 0;
}
