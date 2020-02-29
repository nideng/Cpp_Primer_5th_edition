/*
why is s a reference to const but occurs is a plain reference?
Because s should not be changed by this function, but occurs result must be calculated
by the function, it changes.

Why are these parameters references, but the char parameter c is not?
Because c may be a temp varable, such as find_char(s, 'a', occurs)

What would happen if we made s a plain reference?
What if we made occurs a reference to const?
s could be changed in the function, this may cause some safe problems.
and occurs would not be changed.so occurs = 0; is an error.

*/