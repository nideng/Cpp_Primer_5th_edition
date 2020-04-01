
#include<iostream>
#include<memory>
using std::ostream;
namespace EX16_28_b
{
	class DebugDelete {
	public:
		template<typename T>void operator()(T* p)const
		{
			std::cout << "deleting unique_ptr" << std::endl;
			delete p;
		}
	};
}
