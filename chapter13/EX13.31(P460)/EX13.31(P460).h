#ifndef HASPTR_H
#define HASPTR_H
#include<iostream>
#include<string>
using std::string;
using std::ostream;
class HasPtr {
public:
	friend void swap(HasPtr&, HasPtr&);
	HasPtr(const string& s = string()) :
		ps(new string(s)), i(0), use(new size_t(1)) {};
	HasPtr(const HasPtr& p) :
		ps(p.ps), i(p.i), use(p.use) {
		++* use;
	}
	HasPtr& operator = (HasPtr);
	friend bool operator<(const HasPtr& lhs, const HasPtr& rhs);
	friend ostream& operator<<(ostream&, const HasPtr&);
	~HasPtr();
private:
	string* ps;
	int i;
	size_t* use;
};
HasPtr& HasPtr::operator=(HasPtr rhs)
{
	swap(*this, rhs);
	return *this;
}
HasPtr::~HasPtr()
{
	if (--*use == 0)
	{
		delete ps;
		delete use;
	}
}
void swap(HasPtr& lhs, HasPtr& rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, lhs.i);
	swap(lhs.use, rhs.use);
	std::cout << "call swap(HasPtr& lhs,HasPtr& rhs)" << std::endl;
}
bool operator<(const HasPtr& lhs, const HasPtr& rhs)
{
	return *lhs.ps < *rhs.ps;
}
ostream& operator<<(ostream& os, const HasPtr& h)
{
	os << *h.ps;
	return os;
}
#endif // !HASPTR_H
