#ifndef STRVEC_H
#define STRVEC_H
#include<string>
#include<utility>
#include<memory>
#include<stdexcept>
#include<initializer_list>
using std::string;
using std::pair;
using std::allocator;
using std::invalid_argument;
using std::initializer_list;
class StrVec
{
	friend bool operator==(const StrVec&, const StrVec&);
	friend bool operator!=(const StrVec&, const StrVec&);
	friend bool operator<(const StrVec&, const StrVec&);
	friend bool operator>(const StrVec&, const StrVec&);
	friend bool operator<=(const StrVec&, const StrVec&);
	friend bool operator>=(const StrVec&, const StrVec&);
public:
	StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const StrVec&);
	StrVec(StrVec&&)noexcept;
	StrVec(initializer_list<string>);
	StrVec& operator= (const StrVec&);
	StrVec& operator=(StrVec&&)noexcept;
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
		for (auto p = first_free; p != elements;)
			alloc.destroy(--p);
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
	auto last = uninitialized_copy(make_move_iterator(begin()),
		make_move_iterator(end()), newdata);
	free();
	elements = newdata;
	first_free = last;
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
StrVec::StrVec(StrVec&& s)noexcept
	:elements(s.elements), first_free(s.first_free), cap(s.cap)
{
	s.elements = s.first_free = s.cap = nullptr;
}
StrVec& StrVec::operator=(StrVec&& rhs)noexcept
{
	if (this != &rhs)
	{
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}
bool operator==(const StrVec& lhs, const StrVec& rhs)
{
	return (lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin()));
}
bool operator!=(const StrVec& lhs, const StrVec& rhs)
{
	return !(lhs == rhs);
}
bool operator<(const StrVec& lhs, const StrVec& rhs)
{
	return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

bool operator>(const StrVec& lhs, const StrVec& rhs)
{
	return rhs < lhs;
}

bool operator<=(const StrVec& lhs, const StrVec& rhs)
{
	return !(rhs < lhs);
}

bool operator>=(const StrVec& lhs, const StrVec& rhs)
{
	return !(lhs < rhs);
}
#endif