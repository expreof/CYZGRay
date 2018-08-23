#pragma once
#include "Vector.h"
#include <algorithm>

class BBox
{
public:
	Vector pMin, pMax;
public:
	BBox()
	{
		pMin = Vector(INFINITY, INFINITY, INFINITY);
		pMax = Vector(-INFINITY, -INFINITY, -INFINITY);
	}
	//��Χһ��������
	BBox(const Vector& p) :pMin(p), pMax(p) {}
	//��������
	BBox(const Vector& p1, const Vector& p2)
	{
		pMin = Vector(std::min(p1.x, p2.y), std::min(p1.y, p2.y), std::min(p1.z, p2.z));
		pMax = Vector(std::max(p1.x, p2.x), std::max(p1.y, p2.y), std::max(p1.z, p2.z));
	}
	//������Χ�к�һ������°�Χ��
	friend BBox Union(const BBox& b, const Vector& p);
	friend BBox Union(const BBox& b, const BBox& b2);
	bool Overlaps(const BBox& b) const
	{
		bool x = (pMax.x >= b.pMin.x) && (pMin.x <= b.pMax.x);
		bool y = (pMax.y >= b.pMin.y) && (pMin.y <= b.pMax.y);
		bool z = (pMax.z >= b.pMin.z) && (pMin.z <= b.pMax.z);
		return (x && y && z);
	}
};