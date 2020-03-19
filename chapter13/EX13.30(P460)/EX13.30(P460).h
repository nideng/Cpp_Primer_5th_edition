#ifndef HASPTR_H
#define HASPTR_H
#include<iostream>
#include<string>
using std::string;
class HasPtr {
public:
	friend void swap(HasPtr&, HasPtr&);
	HasPtr(const string& s = string()) :
		ps(new string(s)), i(0), use(new size_t(1)) {};
	HasPtr(const HasPtr& p) :
		ps(p.ps), i(p.i), use(p.use) {
		++* use;
	}
	HasPtr& operator = (const HasPtr&);
	~HasPtr();
private:
	string* ps;
	int i;
	size_t* use;
};
HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
	++* rhs.use;
	if (-- * use == 0) {
		delete ps;
		delete use;
	}
	ps = rhs.ps;
	i = rhs.i;
	use = rhs.use;
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
	std::cout << "call swap(HasPtr& lhs,HasPtr& rhs)" << std::endl;
}
#endif // !HASPTR_H
