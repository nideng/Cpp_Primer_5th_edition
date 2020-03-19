/*
Because the local variable ret here is an Lvalue,
so when we call ret.sorted(), we are actually not calling 
the member function Foo Foo::sorted() && as expected,
but Foo Foo::sorted() const & instead. As a result,
the code will be trapped into a recursion and causes a 
deadly stack overflow.
*/