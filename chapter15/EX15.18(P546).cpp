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
};
struct Prot_Derv:protected Base
{
	int f() { return prot_mem; }
};
struct Priv_Derv:private Base
{
	int f() { return prot_mem; }
};
struct Derived_from_public:public Pub_Derv
{
	int use_base() { return prot_mem; }
};
struct Derived_from_protected:public Prot_Derv
{
	int use_base() { return prot_mem; }
};
struct Derived_from_Private:public Priv_Derv
{
	//int use_base() { }
};
int main()
{
	Pub_Derv d1;
	Priv_Derv d2;
	Base* p = &d1;
	//p = &d2;
	//p = &d3;
	Derived_from_public dd1;
	Derived_from_Private dd2;
	Derived_from_protected dd3;
	p = &dd1;
	//p = &dd2;
	//p = &dd3;

}
/*
User code may use the derived-to-base conversion only if D inherits publicly from B. 
User code may not use the conversion if D inherits from B using either protected or private.
*/