/*
Because the type of i is std::vector<std::string>::size_type
which is an unsigned.When any argument less than 0 is passed in,
it will convert to a number greater than 0. In short 
std::vector<std::string>::size_type will ensure it is a positive
number or 0.
*/