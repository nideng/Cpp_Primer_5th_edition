/*
keyword explicit prevents automatic conversion from an 
initializer_list to StrBlob.

Pros
The compiler will not use this constructor in an automatic conversion.
We can realize clearly which class we have used.

Cons
We always uses the constructor to construct a temporary StrBlob object.
cannot use the copy form of initialization with an explicit constructor.
not easy to use.
*/