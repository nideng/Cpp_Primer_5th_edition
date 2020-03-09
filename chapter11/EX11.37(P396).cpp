/*
Ordered Associative Container:

Standard Traversal encounters elements in sorted order
Order predicate may be specified
Default order predicate is "less than", defined using operator< for the element type
Popular implementations: OrderedVector, BinarySearchTree
Search operations required to have O(log n) runtime
Insert, Remove operations should either be seldom used or have O(log n) runtime

Unordered Associative Container:

Standard Traversal encounters elements in unspecified order
Search, Insert, Remove operations should have average-case constant runtime
Popular implementations use hashing
*/