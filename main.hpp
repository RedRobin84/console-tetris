#pragma once

#include <string>
#include <array>
#include <compare>
#include <iterator>

const int ROTATION_NUMBER = 4;
const int PIECE_POINT_NUMBER = 4;

struct Point 
{
	int x;
	int y;

	auto operator<=>(const Point&) const = default;
};

struct Rotation
{
	const std::array<Point, PIECE_POINT_NUMBER> coordinates;
};

struct Piece
{
	const std::array<Rotation, ROTATION_NUMBER> rotations;
	const Rotation* current_rotation = rotations.begin();

	void nextRotation() {
		auto next_element = std::next(current_rotation);
		if (next_element == rotations.cend()) {
			current_rotation = rotations.cbegin();
			return;
		}
		current_rotation = next_element;
	}

	void previousRotation() {
		if (current_rotation == rotations.cbegin()) {
			current_rotation = &rotations.back();
			return;
		}
		current_rotation = std::prev(current_rotation);
	}
};

const std::string play_field = R"(
XXXXXXXXXXXXXXXXXXXXXXXXX  
X          X    Score   X
X          X            X
X          X            X
X          X            X
X          X            X
X          X            X
X          X            X
X          X            X
X          X            X
X          X            X
XXXXXXXXXXXXXXXXXXXXXXXXX
)";

const int MIN = 1;
const int MAX = 10;

const Point UPPER_LEFT_BORDER {MIN, MIN}; 
const Point UPPER_RIGHT_BORDER {MAX, MIN}; 
const Point BOTTOM_LEFT_BORDER {MIN, MAX}; 
const Point BOTTOM_RIGHT_BORDER {MAX, MAX}; 
const Point TOP_CENTER {MAX / 2, MIN}; 

const int ROWS {MAX};
const int COLUMNS {MAX};

const char* DEFAULT_CHAR = "O"; 

class Position {
	private: 
		Point value;

	public:
		const int getX() const {
			return value.x;
		}
		const int getY() const {
			return value.y;
		}
};
