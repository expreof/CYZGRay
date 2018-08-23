#pragma once
#include <cmath>
#include <cassert>

class Vector
{
public:
	double x = 0;
	double y = 0;
	double z = 0;
public:
	Vector() = default;
	Vector(double xx, double yy, double zz) :x(xx), y(yy), z(zz) {}

	Vector operator+(const Vector& v) const
	{
		return Vector(x + v.x, y + v.y, z + v.z);
	}
	Vector& operator+=(const Vector& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}
	Vector operator-(const Vector& v) const
	{
		return Vector(x - v.x, y - v.y, z - v.z);
	}
	Vector& operator-=(const Vector& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}
	Vector operator*(double s) const
	{
		return Vector(s * x, s * y, s * z);
	}
	Vector& operator*=(double s)
	{
		x *= s;
		y *= s;
		z *= s;
		return *this;
	}
	Vector operator/(double s) const
	{
		assert(s);
		double inv = 1.0 / s;
		return Vector(x*inv, y*inv, z*inv);
	}
	Vector& operator/=(double s)
	{
		assert(s);
		double inv = 1.0 / s;
		x *= inv;
		y *= inv;
		z *= inv;
		return *this;
	}
	Vector operator-() const
	{
		return Vector(-x, -y, -z);
	}

	double length2() const
	{
		return x * x + y * y + z * z;
	}
	double length() const
	{
		return sqrt(length2());
	}
};

using Point = Vector;

Vector operator*(double s, const Vector& v)
{
	return v * s;
}
double dot(const Vector& a, const Vector& b)
{
	return a.x*b.x + a.y*b.y + a.z*b.z;
}
double absdot(const Vector& a, const Vector& b)
{
	return abs(dot(a, b));
}
Vector cross(const Vector& v1, const Vector& v2)
{
	return Vector(v1.y*v2.z - v1.z*v2.y, v1.z*v2.x - v1.x*v2.z, v1.x*v2.y - v1.y*v2.x);
}
Vector normalize(const Vector& v)
{
	return v / v.length();
}