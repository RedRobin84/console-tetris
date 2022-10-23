#include "main.hpp"
#include <ncurses.h>
#include <chrono>
#include <thread>
#include <algorithm>

const Point starting_position {TOP_CENTER};

void draw_on_pos(const Point& point) {
	mvprintw(point.y, point.x, DEFAULT_CHAR);
}

const void render(const Piece& piece, const Position& pos) {
    std::for_each(piece.current_rotation->coordinates.cbegin(),
	piece.current_rotation->coordinates.cend(),
	[&pos](const Point& p) {
            draw_on_pos(pos.for_point(p));
        });
}

int main() {
    initscr();
    cbreak();              // pass key presses to program, but not signals
    noecho();              // don't echo key presses to screen
    keypad(stdscr, TRUE);  // allow arrow keys
    timeout(0);            // no blocking on getch()
    curs_set(0);           // set the cursor to invisible
    Position current_pos {starting_position};
    bool running = true;
    auto area {play_field.substr(1)};
    auto start = std::chrono::steady_clock::now();
    std::vector<int> completed_lines_indexes;
    completed_lines_indexes.reserve(4);

    while(running) {
	printw(area.c_str());
	render(L, current_pos);
	refresh();
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
    	switch (getch()) {
            case KEY_LEFT:
		if (not collides(L.get_current_rotation(), current_pos.next_left(), area)) {
		    current_pos.move_left();
		}
                break;
            case KEY_RIGHT:
		if (not collides(L.get_current_rotation(), current_pos.next_right(), area)) {
		    current_pos.move_right();
		}
	        break;
	    case KEY_UP:
		if (not collides(*L.next_rotation(), current_pos.getCoordinates(), area)) {
		    L.current_rotation = L.next_rotation();
		}
		break;
	    case KEY_DOWN:
		if (not collides(*L.previous_rotation(), current_pos.getCoordinates(), area)) {
		    L.current_rotation = L.previous_rotation();
		}
		break;
	    case 'q':
		running = false;
		continue;
	}
	if (since(start).count() > 1000) {
	    if (collides(L.get_current_rotation(), current_pos.next_down(), area)) {
	        update_area(L.current_rotation, current_pos.getCoordinates(), area);
		set_indexes_of_completed_lines(completed_lines_indexes, area);
		if (not completed_lines_indexes.empty()) {
		    rebuild_area_with_non_completed_lines(area, completed_lines_indexes);
		    completed_lines_indexes.clear();
		}
		current_pos = {starting_position};
	    } else {
	        current_pos = current_pos.next_down();
	    }
	//if current rotation collides with next down position
	//write current rotation to current position in area
	//check for completed rows, if present, delete them and then merge not completed ones
	//create new Piece - if piece collides on creation - running false
	//else current_pos = next down position
		start = std::chrono::steady_clock::now();
	}
	clear();
    }

    endwin();
    return 0;
}

