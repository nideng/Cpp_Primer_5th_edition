/*
local variable : Variables defined inside a block;
parameter: Local variables declared inside the function parameter list
local static variable :
local static variable£¨object£© is initialized before the first time execution passes through 
the object¡¯s definition.Local statics are not destroyed when a function ends; 
they are destroyed when the program terminates.
*/
// example
#include<iostream>
using namespace std;
int count_add(int n)       // n is a parameter.
{
    static int ctr = 0;    // ctr is a static variable.
    ctr += n;
    return ctr;
}

int main()
{
    for (int i = 0; i != 10; ++i)  // i is a local variable.
        cout << count_add(i) << endl;
    return 0;
}