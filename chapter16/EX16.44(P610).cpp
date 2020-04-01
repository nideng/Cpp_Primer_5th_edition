/*
if g¡¯s function parameter is declared as T (not T&&).

g(i);       --  T is deduced as int
g(ci);      --  T is deduced as int, const is ignored.
g(i * ci);  --  T is deduced as int, (i * ci) returns rvalue which is copied to
                      T
 What if g¡¯s function parameter is const T&?

 g(i)        --  T is deduced as int  , val : const int&
 g(ci)       --  T is deduced as int  , val : const int&
 g(i * ci)   --  T is deduced as int  , val : const int&(see example on page 687)
*/