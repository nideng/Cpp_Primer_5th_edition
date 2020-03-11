#include"EX12.32(P435).h"
using namespace std;
void runQueries(ifstream& infile)
{
	TextQuery tq(infile);
	while (true)
	{
		cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q")break;
		print(cout, tq.query(s)) << endl;
	}
}
int main()
{
	ifstream infile("EX12.32(P435).txt");
	runQueries(infile);
	return 0;
}