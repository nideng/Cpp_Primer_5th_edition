/*
Pointer addition is forbidden in C++, you can only subtract two pointers.
The reason for this is that subtracting two pointers gives a logically explainable result- the offset in memory between two pointers.
Similarly, you can subtract or add an integral number to / from a pointer, 
which means "move the pointer up or down".
Adding a pointer to a pointer is something which is hard to explain.
What would the resulting pointner represent ? 
If by any chance you explicitly need a pointer to a place in memory whose address is the sum of some other two addresses, 
you can cast the two pointers to int, add ints, and cast back to a pointer.
Remember though, that this solution needs huge care about the pointer arithmeticand is something you really should never do.
*/
