/*
cval = 'a' + 3 :  'a' promoted to int, then the result of ('a' + 3)(int) converted to char.
fval = ui - ival * 1.0 :  ival converted to double , ui also converted to double. 
                                           then that double converted(by truncation) to float.
dval = ui * fval :  ui promoted to float. then that float converted to double.
cval = ival + fval + dval :  ival converted to float, then that float and fval converted to double.
                                               At last, that double converted to char(by truncation).
*/