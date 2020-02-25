/*
void* is a special pointer that may point to any type, hence void *p=&i is legal.
For type safety, C++ forbids implicit conversions like long *lp = &i;, thus such code is illegal
*/