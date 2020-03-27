#ifndef QUERY_H
#define QUERY_H

#include"TextQuery.h"
using std::string;
using std::shared_ptr;
using std::ostream;
class Query_base
{
	friend class Query;
protected:
	using liine_no = TextQuery::line_no;
	virtual QueryResult eval(const TextQuery&)const = 0;
	virtual string rep()const = 0;
};
class Query {
	friend Query operator~(const Query&);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
public:
	Query(const string&);
	QueryResult eval(const TextQuery& t)const{return q->eval(t);}
	string rep()const {  return q->rep(); }

	Query(const Query& qr) :q(qr.q), use(qr.use) { ++* use; }
	Query& operator=(const Query& rhs)
	{
		++* rhs.use;
		if (-- * use == 0)
		{
			delete q;
			delete use;
		}
		q = rhs.q;
		use = rhs.use;
		return *this;
	}
	~Query() { 
		if (-- * use == 0)
		{
			delete q;
			delete use;
		}
	}
private:
	Query(Query_base* query) :q(query),use(new size_t(1)) {}
	Query_base* q;
	size_t* use;
};
inline ostream& operator<<(ostream& os, const Query& query)
{
	return os << query.rep();
}

class WordQuery :public Query_base {
	friend class Query;
	WordQuery(const string& s) :query_word(s) {}
	QueryResult eval(const TextQuery& t)const 
	{
		return t.query(query_word);
	}
	string rep()const {
		return query_word; 
	}
	string query_word;
};

inline Query::Query(const string& s) :q(new WordQuery(s)),use(new size_t(1)) {}

class NotQuery :public Query_base
{
	friend Query operator~(const Query&);
	NotQuery(const Query& q) :query(q) {}
	string rep()const {
		return "~(" + query.rep() + ")"; 
	}
	QueryResult eval(const TextQuery&)const;
	Query query;
};
inline Query operator~(const Query& operand)
{
	return Query(new NotQuery(operand));
}

class BinaryQuery :public Query_base
{
protected:
	BinaryQuery(const Query& l, const Query& r, string s):
		lhs(l),rhs(r),opSym(s){}
	string rep()const {
		return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
	}
	Query lhs, rhs;
	string opSym;
};

class AndQuery :public BinaryQuery {
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query& left,const Query& right):
		BinaryQuery(left,right,"&"){}
	QueryResult eval(const TextQuery&)const;
};
inline Query operator&(const Query& lhs, const Query& rhs)
{
	return Query(new AndQuery(lhs, rhs));
}

class OrQuery :public BinaryQuery {
	friend Query operator|(const Query&, const Query&);
	OrQuery(const Query& left,const Query& right)
		:BinaryQuery(left,right,"|"){}
	QueryResult eval(const TextQuery&)const;
};
inline Query operator|(const Query& lhs, const Query& rhs)
{
	return Query(new OrQuery(lhs, rhs));
}

#endif // !QUERY_H