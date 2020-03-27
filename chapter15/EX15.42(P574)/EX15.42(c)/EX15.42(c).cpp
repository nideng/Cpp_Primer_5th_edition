#include"Query.h"
using std::ifstream;
using std::cout; using std::cin; using std::endl;

int main()
{
	std::ifstream infile("EX15.42(c).txt");
	TextQuery tq(infile);
	Query q =Query("fiery")&Query("bird")|Query("wind");
	print(cout,q.eval(tq),2,3);
	return 0;
}