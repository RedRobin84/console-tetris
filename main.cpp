#include "main.hpp"
#include <ncurses.h>
#include <chrono>
#include <thread>
#include <algorithm>


Piece L {
	std::array<Rotation, ROTATION_NUMBER>{
		std::array<Point, PIECE_POINT_NUMBER>{Point{1, 0}, Point{1, 1}, Point{1, 2}, Point{2, 2}},
		std::array<Point, PIECE_POINT_NUMBER>{Point{0, 2}, Point{0, 1}, Point{1, 1}, Point{2, 1}},
		std::array<Point, PIECE_POINT_NUMBER>{Point{0, 0}, Point{1, 0}, Point{1, 1}, Point{1, 2}},
		std::array<Point, PIECE_POINT_NUMBER>{Point{0, 1}, Point{1, 1}, Point{2, 1}, Point{2, 0}}
	}
};

const Point starting_position {TOP_CENTER};


void draw_on_pos(const Point& point) {
	mvprintw(point.y, point.x, DEFAULT_CHAR);
}

bool collides(const Rotation& rotation, const Position& position, const std::string& area) {
	return	std::any_of(rotation.coordinates.cbegin(), rotation.coordinates.cend(),
			[&area, &position](const Point& p) {
			return area[(p.x + position.get_x()) + (p.y * position.get_y())] != ' ';
			});
}

int main() {
    initscr();
    cbreak();              // pass key presses to program, but not signals
    noecho();              // don't echo key presses to screen
    keypad(stdscr, TRUE);  // allow arrow keys
    timeout(0);            // no blocking on getch()
    curs_set(0);           // set the cursor to invisible
    Point current_pos = starting_position;
    bool running = true;
    const auto render_result {play_field.substr(1)};

    while(running) {
    	switch (getch()) {
    		case KEY_LEFT:
			break;
		case KEY_RIGHT:
			break;
		case KEY_UP:
			break;
		case KEY_DOWN:
			break;
		case 'q':
			running = false;
			continue;
	}

    	printw(render_result.c_str());
	std::for_each(L.current_rotation->coordinates.cbegin(), L.current_rotation->coordinates.cend(), 
			[&current_pos](const Point& p) {
                        draw_on_pos({p.x + current_pos.x, p.y + current_pos.y});
                        });
    	refresh();
    	std::this_thread::sleep_for(std::chrono::milliseconds(1000)); 
   	clear();
	current_pos.y++;
    }
    endwin();
    return 0;
}

