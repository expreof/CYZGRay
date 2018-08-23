#pragma once
#include <algorithm>
#include <cmath>
#include <cassert>

using std::min;
using std::max;

inline double Lerp(double t, double v1, double v2)
{
	return (1 - t) * v1 + t * v2;
}