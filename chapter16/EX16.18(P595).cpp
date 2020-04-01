/*
(a) template <typename T, typename U, typename V> void f1(T, U, V); // identifier 'U'
(b) template <typename T> T f2(int&); // typename would be hidden
(c) template <typename T> inline T foo(T, unsigned int*); // inline must be after template
(d) template <typename T> void f4(T, T); // return type should be provided
(e) typedef char Ctype;
     template <typename T> T f5(Ctype a); //legal,but the typename hides this typedef
*/