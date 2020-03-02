/*
In this case, the constructor initializer makes it appear as if base
is initialized with i and then base is used to initialize rem.
However, rem is initialized first. The effect of this initializer is to 
initialize rem with the undefined value of base!


struct X
{
X(int i,int j):base(i),rem(base%j){}
int base,rem;
}
*/