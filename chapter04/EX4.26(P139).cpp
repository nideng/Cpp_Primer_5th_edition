/*
The C++ standard does not specify the size of integral types in bytes, 
but it specifies minimum ranges they must be able to hold. 
The minimum range of unsigned int is 0 to 65535. 
Since some implementations use only the minimum 16 bits for unsigned int, 
this could cause undefined behavior.

*/