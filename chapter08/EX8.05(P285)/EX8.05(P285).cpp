
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
void fun(const string& filename, vector<string>& vec)
{
	ifstream ifs(filename);
	if (ifs)
	{
		string buf;
		while (ifs>>buf)
			vec.push_back(buf);
	}
}
int main()
{
	vector<string>vec1{ "C++ Primer","5th","ISBN:978-7-121-15535-2","Author:Stanley B.Lippman" };
	ofstream ofs("EX8.05(P285).txt");
	if (ofs)
	{
		for (const auto& e : vec1)
			ofs << e << endl;
	}

	vector<string>vec2;
	fun("EX8.05(P285).txt", vec2);
	for (const auto& str : vec2)
		cout << str << endl;
	return 0;
}
