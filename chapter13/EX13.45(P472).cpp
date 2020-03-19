/*
Definition£º
lvalue reference: reference that can bind to an lvalue. (Regular reference)
rvalue reference: reference to an object that is about to be destroyed.

We can bind an rvalue reference to expression that require conversion, 
to literals, or to expressions that return an rvalue, 
but we cannot directly bind an rvalue reference to an lvalue.

lvalue : functions that return lvalue references, assignment, 
        subscript, dereference, and prefix increment/decrement operator.
rvalue const reference : functions that return a non-references,
arithmetic, relational bitwise, postfix increment/decrement operators.

*/