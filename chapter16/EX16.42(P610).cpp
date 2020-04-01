//     template <typename T> void g(T&& val);
//     int i = 0; const int ci = i;
//     (a) g(i);
//  since i is lvalue, T is deduced as int&, val is int& && collapsing to int&
//     (b) g(ci);
//  since ci is lvaue, T is deduced as const int&, val is const int& && collapsing to const int&
//     (c) g(i * ci);
//  since i * ci is rvalue, T is deduced as int, val is int&& && colapsing to int&&