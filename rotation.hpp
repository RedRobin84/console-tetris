#pragma once
#include "point.hpp"
#include <array>
#include <set>

const int PIECE_POINT_NUMBER = 4;

struct Rotation
{
	const std::array<Point, PIECE_POINT_NUMBER> coordinates;

	std::set<int> get_line_set() const {
	    std::set<int> lines;
	    std::for_each(coordinates.cbegin(), coordinates.cend(),
		[&lines](const Point& p) {
		lines.insert(p.y);
		});
	    return lines;
	}
};

