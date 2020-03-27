/*
 (a)Query q = Query("fiery") & Query("bird") | Query("wind");

1. Query::Query(const std::string& s) where s == "fiery","bird" and "wind"
2. WordQuery::WordQuery(const std::string& s) where s == "fiery","bird" and "wind"
3. AndQuery::AndQuery(const Query& left, const Query& right);
4. BinaryQuery(const Query&l, const Query& r, std::string s);
5. Query::Query(std::shared_ptr<Query_base> query) 2times
6. OrQuery::OrQuery(const Query& left, const Query& right);
7. BinaryQuery(const Query&l, const Query& r, std::string s);
8. Query::Query(std::shared_ptr<Query_base> query) 2times


(b)cout<<q;

1. query.rep() inside the operator <<().
2. q->rep() inside the member function rep().
3. OrQuery::rep() which is inherited from BinaryQuery.
4. Query::rep() for lhs and rhs: for rhs which is a WordQuery : WordQuery::rep() where query_word("wind") is returned.For lhs which is an AndQuery.
5. AndQuery::rep() which is inherited from BinaryQuery.
6. BinaryQuer::rep(): for rhs: WordQuery::rep() where query_word("fiery") is returned. For lhs: WordQuery::rep() where query_word("bird" ) is returned.

(c)q.eval();

1. q.eval()
2. q->rep(): where q is a pointer to OrQuary.
3. QueryResult eval(const TextQuery& )const override: is called but this one has not been defined yet.


*/

