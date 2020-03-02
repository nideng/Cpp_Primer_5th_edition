/*
Whether the conversion of a string to Sales_data is desired depends
on how we think our users will use the conversion. 
In this case, it might be okay. The string in null_book probably
represents a nonexistent ISBN.

Benefits:
prevent the use of a constructor in a context that requires an implicit 
conversion
we can define a constructor which is used only with the direct form 
of initialization

Drawbacks:
meaningful only on constructors that can be called with a single argument
*/