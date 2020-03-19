/*
swap(lhs.ps, rhs.ps); 
feed the version :swap(std::string*, std::string*) 
swap(lhs.i, rhs.i);
feed the version : swap(int, int).
Both them can't call
swap(HasPtr&, HasPtr&). Thus, 
the calls don't cause a recursion loop.
*/