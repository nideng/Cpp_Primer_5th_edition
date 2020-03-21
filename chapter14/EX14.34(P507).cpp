#include<iostream>
using std::cin; using std::cout; using std::endl;
class func
{
public:
	void operator()(int first, int second, int last)const
	{
		if (first)
			cout << second << endl;
		else cout << last << endl;
	}
};
int main()
{
	func f;
	f(0, 2, 3);
	return 0;
}