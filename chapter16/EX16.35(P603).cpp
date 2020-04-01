/*
template <typename T> T calc(T, int);
template <typename T> T fcn(T, T);
double d; float f; char c;


(a)calc(c, 'c'); legal, type is char.
(b)calc(d, f); legal, type is double.
(c)fcn(c, 'c'); legal, type is char.
(d)fcn(d, f); illegal, d is double, but f is float, they are totally different type.

*/