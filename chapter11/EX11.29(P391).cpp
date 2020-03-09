/*
upper_bound lower_bound:
If the element is not in the multimap, then lower_bound
and upper_bound will return equal iterators; both will
refer to the point at which the key can be inserted without
disrupting the order.

equal_range:
If no matching element is found, then both the first and
second iterators refer to the position where this key can
be inserted.
*/