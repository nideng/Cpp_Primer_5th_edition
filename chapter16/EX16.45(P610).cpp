/*
In this case, when calling on a literal value, say 42. int&& && will collapse to int&&. At last
T is deduced as int. Hence std::vector<T> is instantiated as std::vector<int> which is legal.

 When calling on a variable int. T will be deduced as int&. int & && will collapse to int&.
std::vector<int&> is not legal.
*/