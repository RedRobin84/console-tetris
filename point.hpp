#pragma once
#include <compare>

struct Point 
{
	int x;
	int y;

	auto operator<=>(const Point&) const = default;
};
