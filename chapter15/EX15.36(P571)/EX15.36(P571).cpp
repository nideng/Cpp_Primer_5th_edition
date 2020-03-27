#include"Query.h"

int main()
{
	Query q = Query("fiery") & Query("bird") | Query("wind");
	std::cout << "======================================"<<std::endl;
	std::cout << q << std::endl;
	return 0;
}
/*
Query q = Query("fiery") & Query("bird") | Query("wind");

WordQuery::WordQuery(wind)
Query::Query(const std::string& s) where s=wind
WordQuery::WordQuery(bird)
Query::Query(const std::string& s) where s=bird
WordQuery::WordQuery(fiery)
Query::Query(const std::string& s) where s=fiery
BinaryQuery::BinaryQuery()  where s=&
AndQuery::AndQuery()
Query::Query(std::shared_ptr<Query_base> query)
BinaryQuery::BinaryQuery()  where s=|
OrQuery::OrQuery
Query::Query(std::shared_ptr<Query_base> query)


std::cout << q <<std::endl;


Query::rep()
BinaryQuery::rep()
Query::rep()
WodQuery::rep()
Query::rep()
BinaryQuery::rep()
Query::rep()
WodQuery::rep()
Query::rep()
WodQuery::rep()
((fiery & bird) | wind)
*/