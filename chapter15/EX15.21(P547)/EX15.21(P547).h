#include<string>
using std::string;
static constexpr float pi = 3.1416;
class Shape
{
public:
	Shape() = default;
	Shape(const string& s):name(s){}
	inline virtual float area_or_volume()const = 0;
	virtual ~Shape() = default;
private:
	string name;//shape  name
};
class Shape_2D:public Shape
{
public:
	Shape_2D() = default;
	Shape_2D(const string& s, float x_, float y_) :Shape(s), x(x_), y(y_) {}
	virtual ~Shape_2D() = default;
	inline virtual float area_or_volume()const = 0;
protected:
	float x=0.0;//centre point x coordinate
	float y=0.0;//centre point y coordinate
};
class Shape_3D:public Shape
{
public:
	Shape_3D() = default;
	Shape_3D(const string & s, float x_, float y_,float z_) :Shape(s), x(x_), y(y_),z(z_){}
	virtual ~Shape_3D() = default;
	inline virtual float area_or_volume()const = 0;
protected:
	float x = 0.0;//centre point x coordinate
	float y = 0.0;//centre point y coordinate
	float z = 0.0;//centre point z coordinate
};
class Cell :public Shape_2D
{
public:
	Cell() = default;
	Cell(const string& s,float x_,float y_,float half_len_x_,float half_len_y_)
		:Shape_2D(s,x_,y_),half_len_x(half_len_x_),half_len_y(half_len_y_){}
	virtual ~Cell() = default;
	inline float area_or_volume() const override { return half_len_x * half_len_y * 4; }
protected:
	float half_len_x = 0.0;
	float half_len_y = 0.0;
};
class Circle :public Shape_2D
{
public:
	Circle() = default;
	Circle(const string&s,float x_,float y_,float radius_)
		:Shape_2D(s,x_,y_),radius(radius_){}
	virtual ~Circle() = default;
	inline float area_or_volume()const override { return pi * radius * radius; }
protected:
	float radius = 0.0;

};
class Sphere :public Shape_3D
{
public:
	Sphere() = default;
	Sphere(const string&s,float x_,float y_,float z_,float radius_)
		:Shape_3D(s,x_,y_,z_),radius(radius_){}
	virtual ~Sphere() = default;
	inline float area_or_volume()const override { return 4 * pi * radius * radius * radius / 3; }
protected:
	float radius = 0.0;
};
class Cone : public Shape_3D {
public:
	Cone() = default;
	Cone(const string&s,float x_, float y_, float z_, float radius_, float height_) 
		: Shape_3D(s,x_, y_, z_), radius(radius_), height(height_) {}
	inline float area_or_volume() const override { return pi * radius * radius * height / 3; }
	virtual ~Cone() override {}

protected:
	float radius = 0.0;
	float height= 0.0;
};