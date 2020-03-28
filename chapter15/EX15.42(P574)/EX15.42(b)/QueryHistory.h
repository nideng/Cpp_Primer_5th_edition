#include"Query.h"
#include<stdexcept>
using std::map;
using std::shared_ptr;
using std::domain_error;
class QueryHistory {

public:
	QueryHistory() = default;
	void addQueryHistory(const Query&, unsigned);
	Query& operator()(unsigned i) { return * getQueryHistoy(i); }
private:
	map<unsigned, shared_ptr<Query>>history;
	shared_ptr<Query> getQueryHistoy(unsigned i);
};
shared_ptr<Query> QueryHistory::getQueryHistoy(unsigned i)
{
	if (history.count(i))
		return history[i];
	else
		throw domain_error("no related queery");
}
void QueryHistory::addQueryHistory(const Query&q, unsigned i)
{
	shared_ptr<Query>newdata = std::make_shared<Query>(q);
	history.insert({ i,newdata });
}