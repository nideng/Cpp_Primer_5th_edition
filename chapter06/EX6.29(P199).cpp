/*
Depends on the type of elements of initializer_list. When the type is simple, 
reference is unnecessary. Because it is cheap to copy(such as int). 
Otherwise, Using reference(const) is the better choice.
*/