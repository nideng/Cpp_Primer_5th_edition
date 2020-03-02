class Nodefault
{
private:
	int member;
public:
	Nodefault(int j):member(j) {};
};
class C
{
private:
	Nodefault Cmember;
public:
	//C() { Nodefault i(0); Cmember = i; } This is wrong
	C() :Cmember(0) {}
};																																																												