#include<iostream>
#include<string>
using namespace std;
class HasPtr
{
public:
	HasPtr(const std::string& s = std::string()) :
		ps(new std::string(s)), i(0) {}
	HasPtr(const HasPtr& s);
	HasPtr& operator=(const HasPtr&);
	~HasPtr();
	void print()const { cout << *ps << endl; cout << i << endl; }
	void address()const;
private:
	std::string* ps;
	int i;
};
HasPtr::HasPtr(const HasPtr& s) :ps(new string(*s.ps)), i(s.i) {}
void HasPtr::address()const
{
	cout << this->ps << endl;
}
HasPtr& HasPtr::operator=(const HasPtr& s)
{
	if (this != &s)
	{
		string* temp_ps = new string(*s.ps);
		delete ps;
		ps = temp_ps;
		i = s.i;
	}
	return *this;
}
HasPtr::~HasPtr()
{
	delete ps;
}
int main()
{
	string s = "hello world";
	cout << &s << endl;
	HasPtr ptr1(s);
	ptr1.address();
	HasPtr ptr2(ptr1);
	ptr2.address();
	ptr1.print();
	ptr2.print();
	ptr1 = ptr2;
	ptr1.address();
	ptr1.print();
	ptr2.print();
	return 0;
}