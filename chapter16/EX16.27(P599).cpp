#include <iostream>
using namespace std;


template <typename T> class Stack {
    typedef typename T::ThisDoesntExist StaticAssert; // T::NotExisting doesn't exist at all!
};


void f1(Stack<char>); // No instantiation, compiles

class Exercise {
    Stack<double>& rsd; // No instantiation, compiles (references don't need instantiation, are similar to pointers in this)

    Stack<int>    si; // Instantiation! Doesn't compile!!
};


int main() {

    Stack<char>* sc; // No Instantiation, this compiles successfully since a pointer doesn't need instantiation

    f1(*sc); // Instantiation of Stack<char>! Doesn't compile!!

    int iObj = sizeof(Stack< std::string >); // Instantiation of Stack<std::string>, doesn't compile!!

}