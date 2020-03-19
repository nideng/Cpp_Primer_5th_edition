
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
	HasPtr(HasPtr&&p):
		ps(p.ps), i(p.i), use(p.use) {
		p.ps = nullptr;
		p.use = new size_t(1);
		std::cout << "call HasPtr(HasPtr&&)" << std::endl;
	}
	HasPtr& operator= (const HasPtr&);
	HasPtr& operator=(HasPtr&&);
	friend bool operator<(const HasPtr& lhs, const HasPtr& rhs);
	friend ostream& operator<<(ostream&, const HasPtr&);
	~HasPtr();
private:
	string* ps;
	int i;
	size_t* use;
};
HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
	++* rhs.use;
	if (-- * use == 0)
	{
		delete ps;
		delete use;
	}
	ps = rhs.ps;
	i = rhs.i;
	use = rhs.use;
	return *this;
}
HasPtr& HasPtr::operator=(HasPtr&&rhs)
{
	if (this != &rhs)
	{
		if (-- * use == 0)
		{
			delete ps;
			delete use;
		}
		ps = rhs.ps;
		i = rhs.i;
		use = rhs.use;
		rhs.ps = nullptr;
		rhs.use = new size_t(1);
	}
	std::cout << "call operator=(HasPtr&&)" << std::endl;
	return *this;
}
HasPtr::~HasPtr()
{
	if (-- * use == 0)
	{
		delete ps;
		delete use;
	}
	std::cout << "call ~HasPtr()" << std::endl;
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



