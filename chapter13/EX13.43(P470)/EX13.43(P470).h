#ifndef STRVEC_H
#define STRVEC_H
#include<string>
#include<utility>
#include<memory>
#include<stdexcept>
#include<algorithm>
#include<initializer_list>
using std::string;
using std::pair;
using std::allocator;
using std::invalid_argument;
using std::initializer_list;
class StrVec
{
public:
	StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const StrVec&);
	StrVec(initializer_list<string>);
	StrVec& operator= (const StrVec&);
	~StrVec();
	void push_back(const string&);
	size_t size()const { return first_free - elements; }
	size_t capacity()const { return cap - elements; }
	void reserve(size_t);
	void resize(size_t);
	void resize(size_t, const string&);
	string* begin()const { return elements; }
	string* end()const { return first_free; }
private:
	allocator<string>alloc;
	void chk_n_alloc()
	{
		if (size() == capacity()) reallocate();
	}
	pair<string*, string*>alloc_n_copy(const string*, const string*);
	void free();
	void reallocate();
	void allocate_move(size_t n);
	string* elements;
	string* first_free;
	string* cap;
};
void StrVec::push_back(const string& s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}
pair<string*, string*> StrVec::alloc_n_copy(const string* b, const string* e)
{
	auto data = alloc.allocate(e - b);
	return { data,uninitialized_copy(b,e,data) };
}
void StrVec::free()
{
	if (elements)
	{
		//for (auto p = first_free; p != elements;)
			//alloc.destroy(--p);
		for_each(elements, first_free, [this](string* p) {alloc.destroy(p); });
		alloc.deallocate(elements, cap - elements);
	}
}
StrVec::StrVec(const StrVec& s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}
StrVec::StrVec(initializer_list<string>i1)
{
	auto newdata = alloc_n_copy(i1.begin(), i1.end());
	elements = newdata.first;
	cap = first_free = newdata.second;
}
StrVec::~StrVec() { free(); }
StrVec& StrVec::operator=(const StrVec& rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}
void StrVec::reallocate()
{
	allocate_move(size() ? 2 * size() : 1);
}
void StrVec::reserve(size_t n)
{
	if (n < capacity())
		throw invalid_argument("the parameter must be bigger than the size");
	allocate_move(n);
}
void StrVec::allocate_move(size_t n)
{
	auto newdata = alloc.allocate(n);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + n;
}
void StrVec::resize(size_t n, const string& s)
{
	if (n < size())
	{
		for (auto p = first_free; p != (elements + n);)
			alloc.destroy(--p);
	}
	else
	{
		if (n > capacity()) reserve(n * 2);
		for (auto i = size(); i < n; i++)
			alloc.construct(first_free++, s);
	}
}
void StrVec::resize(size_t n)
{
	resize(n, string());
}
#endif