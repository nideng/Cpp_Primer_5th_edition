//r1 = v2; legal, top-level const in v2 is ignored.
//p1 = p2; illegal, p2 has a low-level const but p1 doesn't.
//p2 = p1; legal, we can convert int* to const int*.
//p1 = p3; illegal, p3 has a low-level const but p1 doesn't.
//p2 = p3; legal, p2 has the same low-level const qualification as p3.