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
	//包围一个独立点
	BBox(const Vector& p) :pMin(p), pMax(p) {}
	//传递两点
	BBox(const Vector& p1, const Vector& p2)
	{
		pMin = Vector(std::min(p1.x, p2.y), std::min(p1.y, p2.y), std::min(p1.z, p2.z));
		pMax = Vector(std::max(p1.x, p2.x), std::max(p1.y, p2.y), std::max(p1.z, p2.z));
	}
	//给定包围盒和一点计算新包围盒
	BBox Union(const BBox& b, const Vector& p)
	{
		BBox ret = b;
		ret.pMin.x = std::min(b.pMin.x, p.x);
		ret.pMin.y = std::min(b.pMin.y, p.y);
		ret.pMin.z = std::min(b.pMin.z, p.z);
		ret.pMax.x = std::max(b.pMax.x, p.x);
		ret.pMax.y = std::max(b.pMax.y, p.y);
		ret.pMax.z = std::max(b.pMax.z, p.z);
		return ret;
	}
};