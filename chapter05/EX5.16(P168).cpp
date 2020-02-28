// while idiomatic
#include<iostream>
using namespace std;
int main()
{
    int i;
    while (cin >> i)
        ;// ...
   // same as for
    for (int i = 0; cin >> i;)
        ;// ...
    // for idiomatic
    int size = 10;
    for (int i = 0; i != size; ++i)
        ;// ...
    // same as while
    int i = 0;
    while (i != size)
    {
        ;// ...
        ++i;
    }
}
/*
I prefer for to while in such cases, because it's terse. 
More importantly, object i won't pollute the external scope after it goes out of the loop.
It's a little bit easier to add new code into the external scope, 
since it reduces the possibility of naming conflicts .That is, a higher maintainability.
Of course, this way makes the code a bit harder to read.
*/