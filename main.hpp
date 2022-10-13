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

	const Rotation* next_rotation() const {
		auto next_element = std::next(current_rotation);
		if (next_element == rotations.cend()) {
			return rotations.cbegin();
		}
		return next_element;
	}

	const Rotation* previous_rotation() const {
		if (current_rotation == rotations.cbegin()) {
			return &rotations.back();
		}
		return std::prev(current_rotation);
	}

	const Rotation& get_current_rotation() {
		return *current_rotation;
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
const int TOTAL_MAX = 25;

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
		const int get_x() const {
			return value.x;
		}
		const int get_y() const {
			return value.y;
		}
		Position(const Point& point) : value(point) {}
};

Piece L {
	std::array<Rotation, ROTATION_NUMBER>{
		std::array<Point, PIECE_POINT_NUMBER>{Point{1, 0}, Point{1, 1}, Point{1, 2}, Point{2, 2}},
		std::array<Point, PIECE_POINT_NUMBER>{Point{0, 2}, Point{0, 1}, Point{1, 1}, Point{2, 1}},
		std::array<Point, PIECE_POINT_NUMBER>{Point{0, 0}, Point{1, 0}, Point{1, 1}, Point{1, 2}},
		std::array<Point, PIECE_POINT_NUMBER>{Point{0, 1}, Point{1, 1}, Point{2, 1}, Point{2, 0}}
	}
};

bool collides(const Rotation& rotation, const Position& position, const std::string& area) {
	return std::any_of(rotation.coordinates.cbegin(), rotation.coordinates.cend(),
			[&area, &position](const Point& p) {
			const auto index = (p.x + position.get_x())
			  + ((p.y + position.get_y()) * TOTAL_MAX); 
			const char ch = area[index];
			printf("collides: index: %d, char: %c\n", index, ch);
			return ch != ' ';
			});
}
