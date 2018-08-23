#pragma once

#include "Ray.h"
#include "cyzg.h"

class BBox
{
public:
	Point pMin, pMax;
public:
	BBox()
	{
		pMin = Point(INFINITY, INFINITY, INFINITY);
		pMax = Point(-INFINITY, -INFINITY, -INFINITY);
	}
	//包围一个独立点
	BBox(const Point& p) :pMin(p), pMax(p) {}
	//传递两点
	BBox(const Point& p1, const Point& p2)
	{
		pMin = Point(std::min(p1.x, p2.y), std::min(p1.y, p2.y), std::min(p1.z, p2.z));
		pMax = Point(std::max(p1.x, p2.x), std::max(p1.y, p2.y), std::max(p1.z, p2.z));
	}
	//给定包围盒和一点计算新包围盒
	friend BBox Union(const BBox& b, const Point& p);
	friend BBox Union(const BBox& b, const BBox& b2);
	//判断两个盒体是否相交
	bool Overlaps(const BBox& b) const;
	//判断给定点是否在盒内
	bool Inside(const Point& pt) const
	{
		return (pt.x >= pMin.x && pt.x <= pMax.x &&
			pt.y >= pMin.y && pt.y <= pMax.y &&
			pt.z >= pMin.z && pt.z <= pMax.z);
	}
	//扩展
	void Expand(double delta)
	{
		pMin -= Vector(delta, delta, delta);
		pMax += Vector(delta, delta, delta);
	}
	//表面积
	double SurfaceArea() const
	{
		Vector d = pMax - pMin;
		return 2 * (d.x*d.y + d.x*d.z + d.y*d.z);
	}
	//体积
	double Volume() const
	{
		Vector d = pMax - pMin;
		return d.x*d.y*d.z;
	}
	//返回最长轴
	int MaximumExtent() const
	{
		Vector diag = pMax - pMin;
		if (diag.x > diag.y && diag.x > diag.z)
			return 0;
		else if (diag.y > diag.z)
			return 1;
		else
			return 2;
	}
	Point Lerp(double tx, double ty, double tz) const
	{
		return Point(::Lerp(tx, pMin.x, pMax.x), ::Lerp(ty, pMin.y, pMax.y), ::Lerp(tz, pMin.z, pMax.z));
	}
	Vector Offset(const Point& p) const
	{
		return Vector((p.x - pMin.x) / (pMax.x - pMin.x),
			(p.y - pMin.y) / (pMax.y - pMin.y),
			(p.z - pMin.z) / (pMax.z - pMin.z));
	}
	//返回包围盒体的球体中心位置和半径
	void BoundingSphere(Point &c, double & rad) const
	{
		c = 0.5*(pMin + pMax);
		rad = Inside(c) ? ((c - pMax).length()) : 0;
	}
	//相交
};