/*
If declaration like that, the call would never succeed to call 
the copy constructor, Sales_data rhs is an argument to a parameter,
thus, we'd need to use the copy constructor to copy the argument,
but to copy the argument, we'd need to call the copy constructor,
and so on indefinitely.
*/