#include <stdio.h>
#include <ncurses.h>
#include <chrono>
#include <thread>
#include <string>
#include <array>
#include <compare>
#include <algorithm>

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
const Point UPPER_RIGHT_BORDER {MIN, MAX}; 
const Point BOTTOM_LEFT_BORDER {MAX, MIN}; 
const Point BOTTOM_RIGHT_BORDER {MAX, MAX}; 
const Point TOP_CENTER {MIN, MAX / 2}; 

const int ROWS {MAX};
const int COLUMNS {MAX};

const char* DEFAULT_CHAR = "O"; 

const Piece L {
	std::array<Rotation, ROTATION_NUMBER>{
		std::array<Point, PIECE_POINT_NUMBER>{Point{1,1}, Point{2,1}, Point{3,1}, Point{3, 2}},
		std::array<Point, PIECE_POINT_NUMBER>{Point{1,1}, Point{2,1}, Point{3,1}, Point{3, 2}},
		std::array<Point, PIECE_POINT_NUMBER>{Point{1,1}, Point{2,1}, Point{3,1}, Point{3, 2}},
		std::array<Point, PIECE_POINT_NUMBER>{Point{1,1}, Point{2,1}, Point{3,1}, Point{3, 2}},
	}
};

Point current_piece_pos {TOP_CENTER};


void draw_on_pos(const Point& point) {
	mvprintw(point.x, point.y, DEFAULT_CHAR);
}

int main() {
    initscr();
    cbreak();              // pass key presses to program, but not signals
    noecho();              // don't echo key presses to screen
    keypad(stdscr, TRUE);  // allow arrow keys
    timeout(0);            // no blocking on getch()
    curs_set(0);           // set the cursor to invisible
    std::string render_result {play_field.substr(1)};
    printw(render_result.c_str());
    std::for_each(L.rotations[0].coordinates.begin(), L.rotations[0].coordinates.end(), draw_on_pos);
    draw_on_pos(current_piece_pos);
    refresh();
    std::this_thread::sleep_for(std::chrono::milliseconds(3000)); 
    clear();
    endwin();
    return 0;
}

