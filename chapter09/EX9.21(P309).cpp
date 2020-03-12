/*
It's the same.
The first call to insert takes the string we just read and puts it in front of 
the element denoted by iter. The value returned by insert is an iterator referring
to this new element. We assign that iterator to iter and repeat the while, 
reading another word. As long as there are words to insert,
each trip through the while inserts a new element ahead of iter and reassigns to 
iter the location of the newly inserted element. That element is the (new) first
element. Thus, each iteration inserts an element ahead of the first element
in the vector.
*/
