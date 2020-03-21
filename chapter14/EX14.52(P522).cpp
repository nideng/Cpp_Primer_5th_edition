/*
ld=si+ld;ambiguous;
ld=ld+si; 
LongDouble operator+(const SmallInt&) and 
LongDouble operator+(LongDouble&, double) both can use, 
LongDouble operator+(const SmallInt&) is more exactly.
*/