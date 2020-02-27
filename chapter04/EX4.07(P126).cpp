/*
Some arithmetic expressions yield undefined results. 
Some of these undefined espressions are due to the nature of mathematics-for example, division by zero.
Others are undefined due to the nature of computers-for example, due to overflow.
Overflow happens when a value is computed that is outside the range of values that the type can represent.

short svalue = 32767; ++svalue; // -32768
unsigned uivalue = 0; --uivalue;  // 4294967295
unsigned short usvalue = 65535; ++usvalue;  // 0
*/