#include <iostream>
#include <sstream>

template <typename T> std::string debug_rep(const T& t);
template <typename T> std::string debug_rep(T* p);

std::string debug_rep(const std::string& s);
std::string debug_rep(char* p);
std::string debug_rep(const char* p);



template<typename T> std::string debug_rep(const T& t)
{
    std::ostringstream ret;
    ret << t;
    return ret.str();
}

// print pointers as their pointer value, followed by the object to which the pointer points
template<typename T> std::string debug_rep(T* p)
{
    std::ostringstream ret;
    ret << "pointer: " << p;

    if (p)
        ret << " " << debug_rep(*p);
    else
        ret << " null pointer";

    return ret.str();
}

// non-template version
std::string debug_rep(const std::string& s)
{
    return '"' + s + '"';
}

std::string debug_rep(char* p)
{
    return debug_rep(std::string(p));
}

std::string debug_rep(const char* p)
{
    return debug_rep(std::string(p));
}

int main()
{
    std::cout << debug_rep(std::string("hello")) << std::endl;
    std::cout << debug_rep("hello") << std::endl;
    std::cout << debug_rep(&std::string("hello")) << std::endl;
}