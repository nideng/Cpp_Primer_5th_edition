#include"StrBlobPtr.h"
#include<memory>
using std::make_shared;
class StrBlobPtrPtr
{
public:
	StrBlobPtrPtr() = default;
	StrBlobPtrPtr(StrBlobPtr&s):p(make_shared<StrBlobPtr>(s)){}
	StrBlobPtr& operator*()const;
	StrBlobPtr* operator->()const;
private:
	shared_ptr<StrBlobPtr>p;
};
StrBlobPtr& StrBlobPtrPtr::operator*()const
{
	return *p;
}
StrBlobPtr* StrBlobPtrPtr::operator->()const
{
	return &this->operator*();
}