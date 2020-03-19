/*
Point global;
Point foo_bar(Point arg)//1
{
	Point local = arg, * heap = new Point(global);//2,3
	*heap = local;
	Point pa[4] = { local,*heap };//4,5
	return *heap;//6
}
*/
#include<iostream>
#include<memory>
using namespace std;
class Point
{
private:
	int x;
	int y;
	static unsigned times;
public:
	Point(const Point& p) :x(p.x), y(p.y) { times++; cout << times << endl; };
	Point() :x(0), y(0) {};
	Point foo_bar(Point);
};
unsigned Point::times = 0;

Point Point::foo_bar(Point arg)
{
	Point local = arg, * heap = new Point(arg);//2,3
	*heap = local;
	Point pa[4] = { local,*heap };//4,5
	return *heap;//6
}
int main()
{
	Point global;
	Point arg;
	arg.foo_bar(arg);//1
	return 0;
}