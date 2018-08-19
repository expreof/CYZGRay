#include <iostream>
#include <cassert>
#include <cmath>

void print(size_t size)
{
#ifndef NDEBUG
	std::cerr << __func__ << ": array size is " << size << std::endl;
#endif
}

int main()
{
	auto a = INFINITY;
	std::cout << a;
	return 0;
}