#include<iostream>
#include<string>
using std::istream;
using std::string;
using std::cin;
using std::cout;
using std::getline;
using std::endl;
class PrintString
{
public:
	PrintString(istream& i=cin):is(i){}
	void operator()()const
	{
		string s;
		getline(is, s);
		cout << (is ? s : string()) << endl;
	}
private:
	istream& is;
};
int main()
{
	PrintString p;
	p();
	return 0;
}