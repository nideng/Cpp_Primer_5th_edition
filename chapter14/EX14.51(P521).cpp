/*
according to the order:
1.exact match
2.const conversion
3.promotion
4.arithmetic or pointer conversion
5.class-type conversion
class-type conversion is the lowest ranked, so void calc(int)
is more viable;
*/