#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	int sum = 0;
	vector<string>vec{ "12","23","34","45","56","67","78","89" };
	for (auto e : vec)
	{
		sum += stoi(e);
	}
	cout << sum << endl;
	cout << "========================" << endl;
	double sum_d = 0;
	vector<string>vec1{ "12.0","23.4","34.5","45.6","56.7","67.8","78.9","89.10" };
	for (auto e : vec1)
		sum_d += stod(e);
	cout << sum_d << endl;
	return 0;
}