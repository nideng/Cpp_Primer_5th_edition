#ifndef STRBLOBPTR
#define STRBLOBPTR
#include<memory>
#include<string>
#include<vector>
#include<initializer_list>
#include<exception>
#include<stdexcept>
using namespace std;
class StrBlob
{
	friend bool operator==(const StrBlob&, const StrBlob&);
	friend bool operator!=(const StrBlob&, const StrBlob&);
	friend bool operator< (const StrBlob&, const StrBlob&);
	friend bool operator> (const StrBlob&, const StrBlob&);
	friend bool operator<=(const StrBlob&, const StrBlob&);
	friend bool operator>=(const StrBlob&, const StrBlob&);
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

bool operator==(const StrBlob& lhs, const StrBlob& rhs)
{
	return lhs.data == rhs.data;
}
bool operator!=(const StrBlob& lhs, const StrBlob& rhs)
{
	return !(lhs == rhs);
}
bool operator< (const StrBlob & lhs, const StrBlob & rhs)
{
	return std::lexicographical_compare(lhs.data->begin(), lhs.data->end(), rhs.data->begin(), rhs.data->end());
}

bool operator> (const StrBlob & lhs, const StrBlob & rhs)
{
	return rhs < lhs;
}

bool operator<=(const StrBlob & lhs, const StrBlob & rhs)
{
	return !(rhs < lhs);
}
bool operator>=(const StrBlob & lhs, const StrBlob & rhs)
{
	return !(lhs < rhs);
}

class ConstStrBlobPtr
{
	friend bool operator==(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs);
	friend bool operator!=(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs);
	friend bool operator< (const ConstStrBlobPtr&, const ConstStrBlobPtr&);
	friend bool operator> (const ConstStrBlobPtr&, const ConstStrBlobPtr&);
	friend bool operator<= (const ConstStrBlobPtr&, const ConstStrBlobPtr&);
	friend bool operator>= (const ConstStrBlobPtr&, const ConstStrBlobPtr&);
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
bool operator==(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs)
{
	return (lhs.curr == rhs.curr);
}

bool operator!=(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs)
{
	return !(lhs == rhs);
}
bool operator< (const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs)
{
	return lhs.curr < rhs.curr;
}

bool operator>(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs)
{
	return lhs.curr > rhs.curr;
}

bool operator<=(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs)
{
	return lhs.curr <= rhs.curr;
}

bool operator>=(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs)
{
	return lhs.curr >= rhs.curr;
}
#endif // !STRBLOBPTR
