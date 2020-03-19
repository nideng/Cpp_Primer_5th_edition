/*
If HasPtr didn't define a destructor, a memory leak would occur, 
compiler synthesized destructor does not manage dynamic memory.

If HasPtr didn't define the copy constructor,
we would get pointer-like copy behaviour. The ps pointer would be 
copied to the left hand side, but ps in the lhs and the rhs 
would still point to the same string on the heap.
*/