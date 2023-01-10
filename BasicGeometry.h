#include <iostream>
#include <cmath>
#include <iomanip>
//2D point
class point2D
{
	public:
	int x;
	int y;
	point2D(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	void display(void);
	void operator += (const point2D&);
	void operator -= (const point2D&);
	void operator *= (const int&);
	void operator /= (const int&);
	point2D operator + (const point2D&) const;
	point2D operator - (const point2D&) const;
	point2D operator * (const int&) const;
	point2D operator / (const int&) const;
};
void point2D::display()
{
	std::cout << this->x << ',' << this->y << '\n';
	return;
}
void point2D::operator += (const point2D& t)
{
	this->x += t.x;
	this->y += t.y;
	return;
}
void point2D::operator -= (const point2D& t)
{
	this->x -= t.x;
	this->y -= t.y;
	return;
}
void point2D::operator *= (const int& t)
{
	this->x *= t;
	this->y *= t;
	return;
}
void point2D::operator /= (const int& t)
{
	this->x /= t;
	this->y /= t;
	return;
}
point2D point2D:: operator + (const point2D& t) const 
{
	point2D p(*this);
	p += t;
	return p;
}
point2D point2D:: operator - (const point2D& t) const
{
	point2D p(*this);
	p -= t;
	return p;
}
point2D point2D:: operator * (const int& t) const
{
	point2D p(*this);
	p *= t;
	return p;
}
point2D point2D:: operator / (const int& t) const 
{
	point2D p(*this);
	p /= t;
	return p;
}
//3D point
class point3D
{
	public:
	int x;
	int y;
	int z;
	point3D(int x, int y, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
	void display(void);
	void operator += (const point3D&);
	void operator -= (const point3D&);
	void operator *= (const int&);
	void operator /= (const int&);
	point3D operator + (const point3D&);
	point3D operator - (const point3D&);
	point3D operator * (const int&);
	point3D operator / (const int&);
};
void point3D::display()
{
	std::cout << this->x << ',' << this->y << ',' << this->z << '\n';
}
void point3D::operator += (const point3D& t)
{
	this->x += t.x;
	this->y += t.y;
	this->z += t.z;
	return;
}
void point3D::operator -= (const point3D& t)
{
	this->x -= t.x;
	this->y -= t.y;
	this->z -= t.z;
	return;
}
void point3D::operator *= (const int& t)
{
	this->x *= t;
	this->y *= t;
	this->z *= t;
	return;
}
void point3D::operator /= (const int& t)
{
	this->x /= t;
	this->y /= t;
	this->z /= t;
	return;
}
point3D point3D::operator + (const point3D& t)
{
	return point3D(this->x + t.x, this->y + t.y, this->z + t.z);
	
}
point3D point3D::operator - (const point3D& t)
{
	return point3D(this->x - t.x, this->y - t.y, this->z - t.z);
}
point3D point3D::operator * (const int& t)
{
	return point3D(this->x * t, this->y * t, this->z * t);
}
point3D point3D::operator / (const int& t)
{
	return point3D(this->x / t, this->y /t, this->z / t);
}

//Dot Product : 
int dot(const point2D& a, const point2D& b)
{
	return (a.x * b.x + a.y * b.y);
}
int dot(const point3D& a, const point3D& b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}
int norm(const point2D& a)
{
	return dot(a, a);
}
int norm(const point3D& a)
{
	return dot(a, a);
}
double abs(const point2D& a)
{
	return std::sqrt(dot(a, a));
}
double abs(const point3D& a)
{
	return std::sqrt(dot(a, a));
}
double projection(const point2D& a, const point2D& b)
{
	return (dot(a,b) / abs(b));
}
double projection(const point3D& a, const point3D& b)
{
	return (dot(a,b) / abs(b));
}
double angle(const point2D& a, const point2D& b)
{
	return std::acos(dot(a,b) / (abs(a) * abs(b)));
}
double angle(const point3D& a, const point3D& b)
{
	return std::acos(dot(a,b) / (abs(a) * abs(b)));
}
//End of dot product


//Cross Product 

point3D cross(const point3D& a, const point3D& b)
{
	return point3D((a.y * b.z - a.z * b.y), (a.z * b.x - a.x * b.z), (a.x * b.y - b.x * a.y));
}
int cross(const point2D& a, const point2D& b)//|a x b| = -|b x a|
{
	return (a.x * b.y - a.y * b.x);
}

//End of Cross Product


//Triple Product 

int tripleProduct(const point3D& a, const point3D& b, const point3D& c)
{
	return dot(a, cross(b, c));
}
//End of Triple Product 


//Check if two line segments intersect : 


//returns whether x projections of two segments overlap. 
int sign(const int& value)
{
	return (value >= 0)? (value > 0? 1 : 0) : -1;
}
bool overlapX(point2D a, point2D b, point2D c, point2D d)
{
	if(a.x > b.x)
	{
		std::swap(a, b);
	}
	if(c.x > d.x)
	{
		std::swap(c, d);
	}
	return (std::max(a.x, c.x) <= std::min(b.x, d.x));
}
//returns whether y projections of two segements overlap.
bool overlapY(point2D a, point2D b, point2D c, point2D d)
{
	if(a.y > b.y)
	{
		std::swap(a, b);
	}
	if(c.y > d.y)
	{
		std::swap(c, d);
	}
	return (std::max(a.y, c.y) <= std::min(b.y, d.y));
}
bool segmentIntersect(const point2D& a, const point2D& b, const point2D& c, const point2D& d)
{
	//Case 1 : Segement CD lies along segment AB
	//In this case the segments intersect iff : there is x intersection and y intersection.
	if((cross(c - a, c - b) == 0) && (cross(d - a, d - b) == 0))
	{
		return overlapX(a, b, c, d) && overlapY(a, b, c, d);
	}
	//Other Case : Segment CD and AB dont not lie along the same line.
	
	return (sign(cross(c - b, c - a)) != sign(cross(d - b, d - a))  && sign(cross(a - c, a - d)) != sign(cross(b - c, b - d)));
	
}

