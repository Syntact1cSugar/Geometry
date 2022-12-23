#include <iostream>
#include <cmath>
// Oriented Area of Triangle (Sign + Magnitude) 
// Sign = negative iff : p3 is counter clockwise to p2
// Sign = positive iff : p3 is clockwise to p2

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
int cross(const point2D& a, const point2D& b)//|a x b| = -|b x a|
{
	return (a.x * b.y - a.y * b.x);
}
int signed_area_parallelogram(const point2D& p1, const point2D& p2, const point2D& p3)
{
	return cross(p2 - p1, p2 - p3);
}
double triangle_area(const point2D& p1, const point2D& p2, const point2D& p3)
{
	return (signed_area_parallelogram(p1, p2, p3)) / 2.0;
}
bool clockwise(const point2D& p1, const point2D& p2, const point2D& p3)
{
	return signed_area_parallelogram(p1, p2, p3) > 0;
}
bool counter_colockwise(const point2D& p1, const point2D& p2, const point2D& p3)
{
	return signed_area_parallelogram(p1, p2, p3) < 0;
}
int main()
{
	return 0;
}
