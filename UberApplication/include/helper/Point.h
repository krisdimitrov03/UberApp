#pragma once
#include <cmath>

struct Point
{
	int x;
	int y;

	double getDistanceTo(const Point& other) const;
};