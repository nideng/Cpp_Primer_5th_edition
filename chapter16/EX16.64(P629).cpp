#include<vector>
#include<string>
#include<iostream>
template<typename T>
unsigned times(const T &t, const std::vector<T>& vec)
{
	unsigned time = 0;
	for (auto e : vec)
	{
		if (e == t)
			++time;
	}
	return time;
}
template<>
unsigned times(const char* const& t, const std::vector<const char*>& vec)
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
	const char* ch = "hello";
	std::vector<const char*>vec{ "hello","world" };
	std::cout<<times(ch, vec)<<std::endl;
}