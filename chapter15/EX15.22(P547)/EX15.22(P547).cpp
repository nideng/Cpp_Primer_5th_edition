#include"EX15.22(P547).h"
#include<iostream>
using std::cout; using std::endl;
void print_area(const Shape& s)
{
	cout << s.area_or_volume() << endl;
}
int main()
{
	Cell c("square", 1, 1, 1, 1);
	Circle cr("circle", 1, 1, 1);
	Sphere s("sphere", 1, 1, 1,1);
	Cone cn("cone", 1, 1, 1, 1, 1);
	print_area(c);
	print_area(cr);
	print_area(s);
	print_area(cn);
}