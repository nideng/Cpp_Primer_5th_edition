/*
This loop let user input a word all the way until the word is sought.
It isn't a good use of assert. because if user begin to input a word, 
the cin would be always have content. so the assert would be always true.
It is meaningless. using assert(s == sought) is better.
*/