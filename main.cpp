#include "main.hpp"
#include <ncurses.h>
#include <chrono>
#include <thread>
#include <algorithm>

const Point starting_position {TOP_CENTER};

void draw_on_pos(const Point& point) {
	mvprintw(point.y, point.x, DEFAULT_CHAR);
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

