/*
(a) 
Within the three options, std::list is the best one. 
To keep sorted alphabetically, each inserting into vector takes theta(n) 
time complexity, whereas that of list (essentially doubly linked list)
takes only O(n). Hence theoretically list has better performance.
(b)
deque. If the program needs to insert or delete elements at the front 
and the back, but not in the middle, use a deque
(c) 
vector, no need that insert or delete at the front or back. 
and If your program has lots of small elements and space overhead matters, 
don’t use list or forward_list.

*/