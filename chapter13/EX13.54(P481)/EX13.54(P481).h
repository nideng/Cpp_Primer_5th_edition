#include<string>
using std::string;
class HasPtr {
	friend void swap(HasPtr&, HasPtr&);
public:
	HasPtr(const string& s = string()):
		ps(new string(s)),i(0){}
	HasPtr(const HasPtr& p);
	HasPtr& operator=(HasPtr);
	HasPtr& operator=(HasPtr&&);
	~HasPtr();
private:
	string* ps;
	int i;
};
HasPtr::HasPtr(const HasPtr& p):
	ps(new string(*p.ps)),i(0){}
HasPtr& HasPtr::operator=(HasPtr p)
{
	swap(*this, p);
	return *this;
}
HasPtr& HasPtr::operator=(HasPtr&&p)
{
	if (this != &p)
	{
		delete ps;
		ps = p.ps;
		i = p.i;
		ps = nullptr;
	}
	return *this;
}
inline
void swap(HasPtr& lhs, HasPtr& rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}
HasPtr::~HasPtr()
{
	delete ps;
}