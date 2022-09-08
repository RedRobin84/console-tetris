#include <stdio.h>
#include <ncurses.h>
#include <chrono>
#include <thread>
#include <string>
#include <list>
#include <array>

struct Point 
{
	int x;
	int y;
};

struct Rotation
{
	const std::list<Point> coordinates;
};

struct Piece
{
	const std::array<Rotation, 4> rotations;
};

const std::string play_field = 1 + R"(
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

const int ROWS {10};
const int COLUMNS {10};

Point current_piece_pos {TOP_CENTER.x, TOP_CENTER.y};

int main() {
    initscr();
    cbreak();              // pass key presses to program, but not signals
    noecho();              // don't echo key presses to screen
    keypad(stdscr, TRUE);  // allow arrow keys
    timeout(0);            // no blocking on getch()
    curs_set(0);           // set the cursor to invisible
    std::string render_result {play_field};
    printw(render_result.c_str());
    mvprintw(current_piece_pos.x, current_piece_pos.y, "O");
    mvprintw(current_piece_pos.x+1, current_piece_pos.y, "O");
    refresh();
    std::this_thread::sleep_for(std::chrono::milliseconds(3000)); 
    clear();
    endwin();
    return 0;
}
