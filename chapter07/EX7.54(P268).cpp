/*
in C++11, constexpr member functions are implicitly const, 
so the "set_xx" functions, which will modify data members,
cannot be declared as constexpr.
*/