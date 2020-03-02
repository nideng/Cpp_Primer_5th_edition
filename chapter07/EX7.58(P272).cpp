/*
(a) static double rate = 6.5;
rate should be a constant expression, or can not initialize in the class;
(b) static const int vecSize=20;
no problem;
(c)static vector<double> vec(vecSize);
we may not specify an in - class initializer inside parentheses.
Fixed :

    // example.h
    class Example {
    public:
        static constexpr double rate = 6.5;
        static const int vecSize = 20;
        static vector<double> vec;
};
// example.C
#include "example.h"
constexpr double Example::rate;
vector<double> Example::vec(Example::vecSize);
*/
