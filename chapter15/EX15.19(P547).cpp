class Base {
public:
	void pub_mem();
protected:
	int prot_mem;
private:
	char priv_mem;
};
struct Pub_Derv :public Base {
	int f() { return prot_mem; }
	void memfcn(Base& b) { b = *this; }
};
struct Prot_Derv :protected Base
{
	int f() { return prot_mem; }
	void memfcn(Base& b) { b = *this; }
};
struct Priv_Derv :private Base
{
	int f() { return prot_mem; }
	void memfcn(Base& b) { b = *this; }
};
struct Derived_from_public :public Pub_Derv
{
	int use_base() { return prot_mem; }
	void memfcn(Base& b) { b = *this; }
};
struct Derived_from_protected :public Prot_Derv
{
	int use_base() { return prot_mem; }
	void memfcn(Base& b) { b = *this; }
};
struct Derived_from_Private :public Priv_Derv
{
	//int use_base() { }
	//void memfcn(Base& b) { b = *this; }
};
/*
Member functions and friends of D can use the conversion to B regardless of how D inherits from B. 
The derived-to-base conversion to a direct base class is always accessible to members and friends of a derived class.

Member functions and friends of classes derived from D may use the derived-to-base conversion if D inherits from B using either public or protected. 
Such code may not use the conversion if D inherits privately from B.
*/