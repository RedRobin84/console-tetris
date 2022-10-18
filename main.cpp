#include "main.hpp"
#include <ncurses.h>
#include <chrono>
#include <thread>
#include <algorithm>

const Point starting_position {TOP_CENTER};

void draw_on_pos(const Point& point) {
	mvprintw(point.y, point.x, DEFAULT_CHAR);
}

void render(const Piece& piece, const Position& pos) {
    std::for_each(piece.current_rotation->coordinates.cbegin(),
	piece.current_rotation->coordinates.cend(),
	[&pos](const Point& p) {
            draw_on_pos({p.x + pos.get_x(), p.y + pos.get_y()});
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
    const auto area {play_field.substr(1)};
    auto start = std::chrono::steady_clock::now();

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
		runGameTickUpdates();
		start = std::chrono::steady_clock::now();
	}
	clear();
    }

    endwin();
    return 0;
}

