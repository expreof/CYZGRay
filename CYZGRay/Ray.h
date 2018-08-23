#pragma once
#include "Vector.h"

class Ray
{
public:
	Point o;
	Vector d;

	mutable double mint = 0;
	mutable double maxt = INFINITY;
	double time = 0;
	int depth = 0;
public:
	Ray() = default;
	Ray(const Point& origin, const Vector& direction, double start, double end = INFINITY, double t = 0, int d = 0) :
		o(origin), d(direction), mint(start), maxt(end), time(t), depth(d) {}
	Ray(const Point& origin, const Vector& direction, const Ray& parent, double start, double end = INFINITY) :
		o(origin), d(direction), mint(start), maxt(end), time(parent.time), depth(parent.depth + 1) {}
	//取射线上点
	Vector operator()(double t) const
	{
		return o + d * t;
	}
};