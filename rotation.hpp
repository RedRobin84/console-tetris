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
	    for (const auto& point : coordinates) {
		lines.insert(point.y);
	    }
	    return lines;
	}
};

