#include<string>
#include<ostream>
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
	   //  this print wanted to call the print from the base class.
       //  however, the class scope base:: was omitted.As a result
       //  it will cause an infinit recursion.
       //  btw, we can add a keyword `override` to show this function
       //  overrides a virtual function from the base class, although
       //  it is not neccessary, but for security, the more, the better.
	   //print(os);
		base::print(os);
		os << " " << i;
	}
private:
	int i;
};
int main()
{
	return 0;
}