#include "BasicGeometry.h"

int signed_area_parallelogram(const point2D& p1, const point2D& p2, const point2D& p3)
{
	return cross(p2 - p1, p2 - p3);
}
double triangle_area(const point2D& p1, const point2D& p2, const point2D& p3)
{
	return (signed_area_parallelogram(p1, p2, p3)) / 2.0;
}
// Vertices of polygon are arranged in clockwise / anticlockwise manner from start to end vertex
double polygon_area(const std::vector<point2D>& vertices)
{
	double totalArea = 0.0;
	int n = (int)vertices.size();
	for(int i=1; i<n-1; ++i)
	{
		totalArea += triangle_area(vertices[0], vertices[i], vertices[i + 1]);
	}
	return std::abs(totalArea);
}

