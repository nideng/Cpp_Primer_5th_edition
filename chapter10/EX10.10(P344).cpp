/*
Cause the library algorithms operate on iterators, not containers.
Thus, an algorithm cannot(directly) add or remove elements.
Besides, the aim of this design is to separate the algorithmsand the operation
provided by member function.
*/