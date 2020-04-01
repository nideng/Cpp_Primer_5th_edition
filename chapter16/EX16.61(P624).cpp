#include<memory>
#include<utility>
#include<iostream>
#include<string>
namespace EX16_61
{
	template<typename T,typename...Args>
	auto make_shared(Args&&...args)->std::shared_ptr<T>
	{
		return std::shared_ptr<T>(new T(std::forward<Args>(args)...));
	}
}
int main()
{
	auto num = EX16_61::make_shared<int>(42);
	std::cout << *num << std::endl;
	auto s = EX16_61::make_shared<std::string>("hello");
	std::cout << *s << std::endl;
	auto ch = EX16_61::make_shared<std::string>(10, 'c');
	std::cout << *ch << std::endl;
}