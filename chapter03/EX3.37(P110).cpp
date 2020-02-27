/*
This code will print all characters in ca, afterwards as no \0 appended, UB would happen.
For most cases, the while loop here won't be terminated as expected and many rubbish would be printed out.
*/