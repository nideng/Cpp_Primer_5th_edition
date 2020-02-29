/*
(a)
int calc(int&, int&); // calls lookup(int&)
int calc(const int&, const int&); // calls lookup(const int&)

(b)
int calc(char*, char*); // calls lookup(char*)
int calc(const char*, const char*); // calls lookup(const char *)

(c)
illegal.both calls lookup(char*)
*/