/*
++i will increment the value of i, and then return the incremented value.
 i = 1;
 j = ++i;
 (i is 2, j is 2)

i++ will increment the value of i, but return the original value that i held before being incremented.
 i = 1;
 j = i++;
 (i is 2, j is 1)

 follow the guideline "prefer ++i over i++" and you won't go wrong.

There's a couple of comments regarding the efficiency of ++i and i++.
In any non-student-project compiler, there will be no performance difference. 
*/

