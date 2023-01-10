#include "BasicGeometry.h"
#include <string>
// Returns the orientation of a point p(x, y) with respect to point B that lies on the line segment AB

std::string pointOrientation(const point2D& A, const point2D& B, const point2D& P)
{
	return (cross(A-B, A-P) > 0)? "ANTICLOCKWISE" : "CLOCKWISE";
}
