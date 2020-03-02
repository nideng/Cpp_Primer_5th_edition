/*
Such as a function like that:
int getSize(const std::vector<int>&);
if vector has not defined its single-argument constructor as explicit.
we can use the function like:
getSize(34);
What is this mean? It's very confused.

But the std::string is different. In ordinary, we use std::string to 
replace const char *(the C language). so when we call a function like that:
void setYourName(std::string); // declaration.
setYourName("pezy"); // just fine.
it is very natural.

*/