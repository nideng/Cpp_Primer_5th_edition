#include<iostream>
#include<vector>
#include<string>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::string;
class PrintString
{
public:
	PrintString(istream& i = cin) :is(i) {}
	string operator()()const
	{
		string s;
		getline(is, s);
		return (is ? s : string());
	}
private:
	istream& is;
};
int main()
{
	vector<string>vec;
	PrintString p;
	while (!p().empty())
		vec.push_back(p());
}