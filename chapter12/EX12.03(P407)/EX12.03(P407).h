#ifndef STRBLOB_H
#define STRLOB_H
#include<memory>
#include<string>
#include<vector>
#include<initializer_list>
#include<exception>
#include<stdexcept>
using namespace std;
class StrBlob
{
public:
	typedef vector<string>::size_type size_type;
	StrBlob();
	StrBlob(initializer_list<string>i1);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const string& t)const { data->push_back(t); }
	void pop_back()const;
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

void StrBlob::pop_back()const
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

#endif // !STRBLOB_H
