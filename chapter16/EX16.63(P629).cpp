#include<vector>
#include<string>
#include<iostream>
template<typename T>
unsigned times(const T& t,const std::vector<T>& vec)
{
	unsigned time = 0;
	for (auto e : vec)
	{
		if (e == t)
			++time;
	}
	return time;
}

int main()
{
	std::vector<double>vec1{ 1.0,2.0,3.0,4.0 };
	std::vector<int>vec2{ 5,4,3,2,1 };
	std::vector < std::string > vec3{ "hello","world" };
	std::cout << times(2.0, vec1) << std::endl;
	std::cout << times(3, vec2) << std::endl;
	std::cout << times(std::string("hello"), vec3) << std::endl;
}