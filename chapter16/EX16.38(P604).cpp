/*
without specified type given, make_shared has no possibility to
to determine how big the size it should allocate, which is the reason.

Depending on the type specified, make_shared allocates proper size of memory
space and returns a proper type of shared_ptr pointing to it.

Because when we call make_shared, it is allowed for no argument. Then, we have nothing to deduce the type of the return type.
*/