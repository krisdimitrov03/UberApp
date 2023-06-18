#include "../../include/helper/Point.h"

double Point::getDistanceTo(const Point& other) const
{
	Point vector = { other.x - x, other.y - y };
	int left = pow(vector.x, 2);
	int right = pow(vector.y, 2);

	return sqrt(left + right);
}