#include"TextQuery.h"
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
	ifstream infile("EX16.22(P597).txt");
	runQueries(infile);
	return 0;
}