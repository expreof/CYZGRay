#include "BBox.h"

BBox Union(const BBox & b, const Point & p)
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

BBox Union(const BBox & b, const BBox & b2)
{
	BBox ret;
	ret.pMin.x = std::min(b.pMin.x, b2.pMin.x);
	ret.pMin.y = std::min(b.pMin.y, b2.pMin.y);
	ret.pMin.z = std::min(b.pMin.z, b2.pMin.z);
	ret.pMax.x = std::max(b.pMax.x, b2.pMax.x);
	ret.pMax.y = std::max(b.pMax.y, b2.pMax.y);
	ret.pMax.z = std::max(b.pMax.z, b2.pMax.z);
	return ret;
}

inline bool BBox::Overlaps(const BBox & b) const
{
	bool x = (pMax.x >= b.pMin.x) && (pMin.x <= b.pMax.x);
	bool y = (pMax.y >= b.pMin.y) && (pMin.y <= b.pMax.y);
	bool z = (pMax.z >= b.pMin.z) && (pMin.z <= b.pMax.z);
	return (x && y && z);
}
