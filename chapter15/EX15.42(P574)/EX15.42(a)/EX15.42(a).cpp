#include"Query.h"
using std::ifstream;
using std::cout; using std::cin; using std::endl;

int main()
{
	std::ifstream infile("EX15.42(a).txt");
	if (infile)
	{
		TextQuery tq(infile);
		Query q = Query("fiery") & Query("bird") | Query("wind");
		print(cout, q.eval(tq));
	}
	return 0;
}


