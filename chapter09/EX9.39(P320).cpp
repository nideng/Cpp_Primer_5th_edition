/*
The while loop will read words from cin and store them in out vector. 
Even if we initially reserved 1024 elements, if there are more words 
read from cin, our vector's capacity will be automatically increased
(most implementations will double the previous capacity) to accommodate
them.

And now comes the catch. resize() is different from reserve().
In this case resize() will add another svec.size()/2 value initialized 
elements to svec. If this exceeds svec.capacity() it will also
automatically increase it to accommodate the new elements.

*/