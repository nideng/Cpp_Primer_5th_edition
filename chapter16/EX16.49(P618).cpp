
#include <iostream>

template <typename T> 
void f(T)
{
    std::cout << "f(T)" << std::endl;
}

template <typename T> 
void f(const T*)
{
    std::cout << "f(const T*)" << std::endl;
}
template <typename T> void g(T)
{
    std::cout << "g(T)"<<std::endl;
}
template <typename T> void g(T*)
{
    std::cout << "g(T*)"<<std::endl;
}
int main()
{
    int i = 42, * p = &i;
    const int ci = 0, * p2 = &ci;
    g(42);// template <typename T> void g(T)
    g(p); //template <typename T> void g(T*)
    g(ci); //template <typename T> void g(T)
    g(p2); //template <typename T> void g(T*)
    f(42);//f(T)
    f(p); //f(T)
    f(ci);//f(T)
    f(p2); //f(const T*)
}