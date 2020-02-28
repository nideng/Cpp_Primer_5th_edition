/*
(a) // Error: should have a break statement
unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
char ch = next_text();
switch (ch) {
case 'a': aCnt++; break;
case 'e': eCnt++; break;
default: iouCnt++; break;
}
(b) // Error: control bypass an explicitly initialized variable ix.
unsigned index = some_value();
int ix;
switch (index) {
case 1:
    ix = get_value();
    ivec[ix] = index;
    break;
default:
    ix = static_cast<int>(ivec.size()) - 1;
    ivec[ix] = index;
}
(c) // Error: case label syntax error
unsigned evenCnt = 0, oddCnt = 0;
int digit = get_num() % 10;
switch (digit) {
case 1: case 3: case 5: case 7: case 9:
    oddcnt++; // oddcnt != oddCnt
    break;
case 2: case 4: case 6: case 8: case 0:
    evencnt++; // evencnt != evenCnt
    break;
}
(d) // Error: case label must be a constant expression
const unsigned ival = 512, jval = 1024, kval = 4096;
unsigned bufsize;
unsigned swt = get_bufCnt();
switch (swt) {
case ival:
    bufsize = ival * sizeof(int);
    break;
case jval:
    bufsize = jval * sizeof(int);
    break;
case kval:
    bufsize = kval * sizeof(int);
    break;
}
*/