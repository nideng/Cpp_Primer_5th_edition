
/*
List:
1.Searching (linear time).
2.Inserting, deleting, moving (takes constant time).
3.Elements may be ordered.
4.Elements may be sorted.
5.Elements may be duplicate.

Set:
1.Searching (logarithmic in size).
2.Insert and delete (logarithimic in general).
3.Elements are un-ordered.
4.Elements are always sorted from lower to higher.
5.Elements are unique.

How to choose:
std::list is O(1) for inserts and deletions.
But you may well need O(n) to find the insertion or deletion
point. std::set is O(log(n)) for inserts and deletions, 
it is usually implemented as a red-black tree.
Consider the effort to find the insert/delete point to 
make your choice.

*/