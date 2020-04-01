/*
make_shared shoudl be a variadic template function that forwards all arguments to
underlying constructors that allocate and initializes an object in dynamic memory and 
at last, build a shared_ptr by wrapping the raw pointer.
*/