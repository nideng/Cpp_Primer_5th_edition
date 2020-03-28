#include"Query.h"
#include"QueryHistory.h"
using std::ifstream;
using std::cout; using std::cin; using std::endl;

int main()
{
	std::ifstream infile("EX15.42(b).txt");
	TextQuery tq(infile);
	Query q1 =Query("fiery")&Query("bird")|Query("wind");
	Query q2 = Query("Daddy");
	Query q3 = ~Query("Alice");
	Query q4 = Query("hair") | Query("Alice");
	Query q5 = Query("hair") & Query("Alice");
	QueryHistory qh;
	qh.addQueryHistory(q1,1);
	qh.addQueryHistory(q2, 2);
	qh.addQueryHistory(q3, 3);
	qh.addQueryHistory(q4, 4);
	qh.addQueryHistory(q5, 5);
	print(cout, qh(1).eval(tq));
	qh(2) = qh(2) & qh(3);
	print(cout, qh(2).eval(tq));
	return 0;
}