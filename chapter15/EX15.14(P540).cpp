#include<string>
#include<iostream>
using std::ostream;
using std::string;
class base {
public:
	string name() { return basename; }
	virtual void print(ostream& os) { os << basename; }
private:
	string basename;
};
class derived :public base {
public:
	void print(ostream& os) override
	{
		base::print(os);
		os << " " << i;
	}
private:
	int i;
};
int main()
{
	base bobj;
	derived dobj;
	base* bp1 = &bobj;
	base& br1 = bobj;
	base* bp2 = &dobj;
	base& br2 = dobj;
	bobj.print(std::cout);//this is an object, so compile time
	dobj.print(std::cout);//this is an object, so compile time.
	bp1->name();//function name is not virtual , so no dynamic binding happens.so compile time
	bp2->name();//function name is not virtual , so no dynamic binding happens.so compile time
	br1.print(std::cout);//run time
	br2.print(std::cout);//run time
	return 0;
}