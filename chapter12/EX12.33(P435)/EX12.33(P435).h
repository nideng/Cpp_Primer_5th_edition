#ifndef TEXTQUERY_H
#define TEXTQUERY_H
#include<map>
#include<set>
#include<fstream>
#include<sstream>
#include<string>
#include<memory>
#include<vector>
#include<iostream>
using namespace std;
class QueryResult;
class TextQuery
{
private:
	map<string, shared_ptr<set<unsigned>>>result_map;
	shared_ptr<vector<string>>input_file;
public:
	TextQuery(ifstream&);
	QueryResult query(const string&)const;
};
class QueryResult
{
private:
	string sought_word;
	shared_ptr<set<unsigned>>lineNo;
	shared_ptr<vector<string>>file;
public:
	QueryResult(const string& s, shared_ptr<set<unsigned>>p, shared_ptr<vector<string>>f)
		:sought_word(s), lineNo(p), file(f) {}
	friend ostream& print(ostream&, const QueryResult&);
	set<unsigned>::iterator begin()const;
	set<unsigned>::iterator end()const;
	shared_ptr<vector<string>> get_file()const;
};

set<unsigned>::iterator QueryResult::begin()const
{
	return lineNo->begin();
}

set<unsigned>::iterator QueryResult::end()const
{
	return lineNo->end();
}
shared_ptr<vector<string>> QueryResult::get_file()const
{
	return make_shared<vector<string>>(file);
}
TextQuery::TextQuery(ifstream& input) :input_file(new vector<string>)
{
	string line, word;
	while (getline(input, line))
	{
		input_file->push_back(line);
		size_t n = input_file->size() - 1;
		istringstream in(line);
		while (in >> word)
		{
			auto& lineNo = result_map[word];
			if (!lineNo)
				lineNo.reset(new set<unsigned>);
			lineNo->insert(n);
		}
	}
}
QueryResult TextQuery::query(const string& s) const
{

	auto r = result_map.find(s);
	shared_ptr<set<unsigned>>nodata(new set<unsigned>);
	if (r == result_map.end())
		return QueryResult(s, nodata, input_file);
	else
		return QueryResult(s, r->second, input_file);
}

ostream& print(ostream& os, const QueryResult& qr)
{
	os << qr.sought_word << " occurs " << qr.lineNo->size()
		<< (qr.lineNo->size() > 1 ? "times" : "time") << endl;
	for (auto e : *(qr.lineNo))
		os << "\t(line " << e + 1 << ") "
		<< *(qr.file->begin() + e) << endl;
	return os;
}
#endif // !TextQuery
