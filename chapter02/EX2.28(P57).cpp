/*
int i, * const cp;       // illegal, cp as a const pointer must initialize.
int* p1, * const p2;     // illegal, p2 as a const pointer must initialize.
const int ic, & r = ic;  // illegal, ic must initialize.
const int* const p3;    // illegal, p3 must initialize.
const int* p;           // legal. a pointer to const int
*/