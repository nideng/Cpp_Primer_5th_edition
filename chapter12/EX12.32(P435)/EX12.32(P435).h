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
#include<initializer_list>
#include<exception>
#include<stdexcept>
using namespace std;
class StrBlob
{
public:
	friend class ConstStrBlobPtr;
	ConstStrBlobPtr begin()const;
	ConstStrBlobPtr end()const;
public:
	typedef vector<string>::size_type size_type;
	StrBlob();
	StrBlob(initializer_list<string>i1);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const string& t) { data->push_back(t); }
	void pop_back();
	string& front();
	const string& front()const;
	string& back();
	const string& back()const;
private:
	shared_ptr<vector<string>>data;
	void check(size_type i, const string& msg)const;
};
StrBlob::StrBlob() :data(make_shared < vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string>i1) : data(make_shared<vector<string>>(i1)) {}

void StrBlob::check(size_type i, const string& msg)const
{
	if (i >= data->size())
		throw out_of_range(msg);
}

void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

string& StrBlob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
}

const string& StrBlob::front() const
{
	check(0, "front on empty StrBlob");
	return data->front();
}

string& StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}
const string& StrBlob::back()const
{
	check(0, "back on empty StrBlob");
	return data->back();
}

class ConstStrBlobPtr
{
public:
	ConstStrBlobPtr() :curr(0) {}
	ConstStrBlobPtr(const StrBlob& a, size_t sz = 0) :
		wptr(a.data), curr(sz) {}
	string& deref()const;
	ConstStrBlobPtr& incr();
private:
	shared_ptr<vector<string>>check(size_t, const string&)const;
	weak_ptr<vector<string>>wptr;
	size_t curr;
};

ConstStrBlobPtr StrBlob::begin()const
{
	return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::end()const
{
	auto ret = ConstStrBlobPtr(*this, data->size());
	return ret;
}

shared_ptr<vector<string>> ConstStrBlobPtr::check(size_t i, const string& msg)const
{
	auto ret = wptr.lock();
	if (!ret)
		throw runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw out_of_range(msg);
	return ret;
}

string& ConstStrBlobPtr::deref()const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

ConstStrBlobPtr& ConstStrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}


class QueryResult;
class TextQuery
{
private:
	map<string, shared_ptr<set<unsigned>>>result_map;
	shared_ptr<StrBlob>input_file;
public:
	TextQuery(ifstream&);
	QueryResult query(const string&)const;
};
class QueryResult
{
private:
	string sought_word;
	shared_ptr<set<unsigned>>lineNo;
	shared_ptr<StrBlob>file;
public:
	QueryResult(const string& s, shared_ptr<set<unsigned>>p, shared_ptr<StrBlob>f)
		:sought_word(s), lineNo(p), file(f) {}
	friend ostream& print(ostream&, const QueryResult&);
};
TextQuery::TextQuery(ifstream& input) :input_file(new StrBlob)
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
		<< (qr.lineNo->size() > 1 ? " times" : " time") << endl;
	for (auto e : *(qr.lineNo))
	{
		ConstStrBlobPtr p(*qr.file, e);
		os << "\t(line " << e + 1 << ") "
			<< p.deref() << endl;
	}
	return os;
}

#endif // !TextQuery
