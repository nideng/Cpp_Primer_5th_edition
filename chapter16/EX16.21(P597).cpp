#include<iostream>
#include<memory>
using std::ostream;
class DebugDelete {
public:
	DebugDelete(ostream& s=std::cerr):os(s){}
	template<typename T>void operator()(T* p)const
	{
		os << "deleting unique_ptr" << std::endl;
		delete p;
	}
private:
	ostream& os;
};

int main()
{
	double* p = new double;
	DebugDelete()(p);
	std::unique_ptr<int, DebugDelete>p1(new int, DebugDelete());
	std::unique_ptr<std::string, DebugDelete>(new std::string("c++ primer"), DebugDelete());
	return 0;
}