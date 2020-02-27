/*
We use prefix and not postfix, just because of the Advice :
Use Postfix Operators only When Necessary on ¡ì4.5.Increment and Decrement Operators.
Advice : Use Postfix Operators only When Necessary
Readers from a C background might be surprised that we use the prefix increment in the programs 
we've written. The reason is simple: The prefix version avoids unnecessary work. 
It increments the value and returns the incremented version.
The postfix operator must store the original value so that it can return the unincremented value 
as its result. If we don¡¯t need the unincremented value,
there¡¯s no need for the extra work done by the postfix operator.
For ints and pointers, the compiler can optimize away this extra work.
For more complicated iterator types, this extra work potentially might be more costly.
By habitually using the prefix versions, we do not have to worry about whether the performance
difference matters.Moreover¡ªand perhaps more importantly¡ªwe can express the intent of our
programs more directly.
So, it's just a good habits. And there are no changes if we have to be made to use the postfix 
versions. 

*/