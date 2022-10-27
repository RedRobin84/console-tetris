#pragma once

#include <string>
#include <array>
#include <compare>
#include <iterator>
#include <vector>
#include <set>

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

	const std::set<int> get_line_set() const {
		std::set<int> lines;
		std::for_each(coordinates.cbegin(), coordinates.cend(),
				[&lines](const Point& p) {
				lines.insert(p.y);
				});
		return lines;
	}
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

const int MIN_X = 0;
const int MIN_X_AREA = 1;
const int MIN_Y = 1; // Skipping first row
const int MAX = 10;
const int ROW_CHARS = 26; //25 + \n

const Point UPPER_LEFT_BORDER {MIN_X, MIN_Y};
const Point UPPER_RIGHT_BORDER {MAX, MIN_Y};
const Point BOTTOM_LEFT_BORDER {MIN_X, MAX};
const Point AREA_BOTTOM_LEFT_BORDER {MIN_X_AREA, MAX};
const Point BOTTOM_RIGHT_BORDER {MAX, MAX};
const Point AREA_BOTTOM_RIGHT_BORDER {MAX, MAX};
const Point TOP_CENTER {MAX / 2, MIN_Y};

const int ROW_NUMBER {MAX};
const int COLUMN_NUMBER {MAX};

const char* DEFAULT_CHAR = "O"; 

class Position {
	private: 
		Point value = {TOP_CENTER};

	public:
		Position() = default;
		Position(const Point& point) : value(point) {}

		const int get_x() const {
			return value.x;
		}
		const int get_y() const {
		return value.y;
		}
		const Point for_point(const Point& point) const {
			return {point.x + get_x(), point.y + get_y()};
		}
		const int get_line(const int y) const {
			return y + get_y();
		}
		const Point getCoordinates() {
			return value;
		}
		const Point next_left() {
			return {value.x - 1, value.y};
		}
		const Point next_right() {
			return {value.x + 1, value.y};
		}
		const Point next_down() {
			return {value.x, value.y + 1};
		}
		void move_left() {
			if (value.x > 0) {
				value.x -= 1;
			}
		}
		void move_right() {
			if (value.x < ROW_NUMBER) {
				value.x += 1;
			}
		}
		void move_down() {
			if (value.y < COLUMN_NUMBER) {
				value.y += 1;
			}
		}
};

const int get_area_index(const Point& rotation_point, const Point& position) {
	return (rotation_point.x + position.x) + ((rotation_point.y + position.y) * ROW_CHARS);
}

bool collides(const Rotation& rotation, const Point& position, const std::string& area) {
	return std::any_of(rotation.coordinates.cbegin(), rotation.coordinates.cend(),
			[&area, &position](const Point& p) {
			const auto index = get_area_index(p, position);
			const char ch = area[index];
			//printf("collides: index: %d, char: %c\n", index, ch);
			return ch != ' ';
			});
}

void update_area(const Rotation* rotation, const Point& position, std::string& area) {
	std::for_each(rotation->coordinates.cbegin(), rotation->coordinates.cend(), 
			[&position, &area](const Point& p) {
			const auto index = get_area_index(p, position);
			area[index] = '0';
			});
}

const int get_line_starting_index(const int line_number) {
    return (line_number * ROW_CHARS) + 1; // + 1 game line begins at 2nd tile
}

auto get_nth_line_end(std::string::iterator line_begin) {
    return line_begin + ROW_CHARS;
}


auto get_nth_line_end(std::string::const_iterator line_begin) {
    return line_begin + ROW_CHARS;
}

auto get_nth_line_begin(const int line_number, std::string& area) {
   return area.begin() + (get_line_starting_index(line_number) - 1); // - 1 for cbegin()
}


auto get_nth_line_begin(const int line_number, const std::string& area) {
   return area.cbegin() + (get_line_starting_index(line_number) - 1); // - 1 for cbegin()
}

bool is_line_completed(const int line, const std::string& area) {
    auto line_begin = get_nth_line_begin(line, area);
    auto line_end = get_nth_line_end(line_begin);
        return std::all_of(line_begin, line_end,
	       [](const char ch) {return ch == '0';});
}

std::set<int> get_completed_lines(const std::set<int>& lines, const Position& pos, const std::string& area) {
	std::set<int> completed_lines;
	std::for_each(lines.cbegin(), lines.cend(), [&completed_lines, &area, &pos]
			(const int line) {
			const auto computed_line = pos.get_line(line);
			if (is_line_completed(computed_line, area)) {
			    completed_lines.insert(line);
			}});
	return completed_lines;
}

void move_line(std::string::iterator line_from_begin, std::string::iterator line_to_begin) {
    auto line_from_end = get_nth_line_end(line_from_begin);
    for (auto from = line_from_begin, to = line_to_begin; from != line_from_end; from++, to++) {
	    *to = *from;
	    *from = ' ';
    }
}

bool line_empty(std::string::iterator line_begin) {
    auto line_end = get_nth_line_end(line_begin);
    return (not std::any_of(line_begin, line_end, [](const char ch) {return ch == '0';}));
}

void rebuild_area_with_non_completed_lines(std::string& area, std::set<int> completed_lines) {
    auto current_line = *completed_lines.rend();
    auto write_line = current_line;
    completed_lines.erase(current_line);
    current_line--;
    while (current_line > 0) {
        if ((not completed_lines.empty()) and (completed_lines.find(current_line) != completed_lines.end())) {
	    completed_lines.erase(current_line);
	    current_line--;
	    continue;
	}
        auto current_line_begin = get_nth_line_begin(current_line, area);
	if (line_empty(current_line_begin)) {
	    break;
	}
        auto write_line_begin = get_nth_line_begin(write_line, area);
	move_line(current_line_begin, write_line_begin);
	current_line--;
	write_line--;
    }
}

template <
    class result_t   = std::chrono::milliseconds,
    class clock_t    = std::chrono::steady_clock,
    class duration_t = std::chrono::milliseconds
>
auto since(std::chrono::time_point<clock_t, duration_t> const& start)
{
    return std::chrono::duration_cast<result_t>(clock_t::now() - start);
}

Piece L {
	std::array<Rotation, ROTATION_NUMBER>{
		std::array<Point, PIECE_POINT_NUMBER>{Point{1, 0}, Point{1, 1}, Point{1, 2}, Point{2, 2}},
		std::array<Point, PIECE_POINT_NUMBER>{Point{0, 2}, Point{0, 1}, Point{1, 1}, Point{2, 1}},
		std::array<Point, PIECE_POINT_NUMBER>{Point{0, 0}, Point{1, 0}, Point{1, 1}, Point{1, 2}},
		std::array<Point, PIECE_POINT_NUMBER>{Point{0, 1}, Point{1, 1}, Point{2, 1}, Point{2, 0}}
	}
};

