#include<iostream>
#include<string>
using namespace std;
class HasPtr
{
public:
	HasPtr(const std::string& s = std::string()):
		ps(new std::string(s)),i(0){}
	HasPtr(const HasPtr& s);
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
int main()
{
	string s = "hello world";
	cout << &s << endl;
	HasPtr ptr1(s);
	ptr1.address();
	HasPtr ptr2(ptr1);
	ptr2.address();
	return 0;
}