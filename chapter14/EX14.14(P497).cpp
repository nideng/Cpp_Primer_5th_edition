/*
The reason is in the number of copying that needs to be 
made: binary operator + creates and returns a new object
that represents a sum, while the compound 
addition-assignment operator modifies the object in place.

If you would like to implement the compound operator in
terms of the binary operator, the sequence of actions would
be as follows:

1.Compound assignment calls the binary operator
2.The binary operator creates a new object from one of the
   objects (copy #1), and puts the sum into it
3.The sum is returned by value (copy #2)
4.The sum object is copied into the object on the left-hand
  side object (copy #3)

 If you do it the other way around, the last copy is
 eliminated:
 
 1.Binary operator creates an object representing the sum
   from the left-hand side object
 2.Binary operator invokes the compound addition-assignment,
   which does not require copying
 3.Binary operator returns the object by value (copy #2)
 4.Therefore, using the compound addition-assignment in the
   implementation of the binary + is more efficient.
*/