/*
rhs parameter is nonreference, which means the parameter is copy
initialized. Depending on the type of the argument, 
copy initialization uses either the copy constructor or 
the move constructor.
lvalues are copied and rvalues are moved.
Thus, in hp = hp2;, hp2 is an lvalue, copy constructor used to 
copy hp2. In hp = std::move(hp2);, move constructor moves hp2.
*/