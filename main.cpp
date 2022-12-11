#include "main.hpp"
#include "score.hpp"
#include "file_ops.hpp"

#include <ncurses.h>
#include <chrono>
#include <thread>
#include <algorithm>
#include <stdlib.h>

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

const void render_score(const std::string& new_score, const Point& pos) {
	mvprintw(pos.y, pos.x, new_score.c_str());
}

constexpr int STARTING_DROP_INTERVAL_MS {1000};
constexpr int AFTER_DROP_DECREMENT_MS {5};
constexpr int MIN_DROP_INTERVAL_LIMIT_MS {300};

constexpr const char *SCORE_FILE = "data.bin";
const Point SCORE_POS {18, 2};
const Point PREV_SCORE_POS {18, 5};

int main() {
    initscr();
    cbreak();              // pass key presses to program, but not signals
    noecho();              // don't echo key presses to screen
    keypad(stdscr, TRUE);  // allow arrow keys
    timeout(0);            // no blocking on getch()
    curs_set(0);           // set the cursor to invisible
    Position current_pos {starting_position};
    int current_piece_index = rand() % pieces.size();
    int drop_interval {STARTING_DROP_INTERVAL_MS};
    bool running = true;
    auto area {play_field.substr(1)};
    auto start = std::chrono::steady_clock::now();
    const Score previous_score = Score(
	read_score_from_binary_file(SCORE_FILE)
	.value_or(0)
	);
    Score score {};

    while(running) {
	printw(area.c_str());
	render(pieces[current_piece_index], current_pos);
	render_score(score.get_score(), SCORE_POS);
	render_score(previous_score.get_score(), PREV_SCORE_POS);
	refresh();
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
    	switch (getch()) {
            case KEY_LEFT:
		if (not collides(pieces[current_piece_index].get_current_rotation(), current_pos.next_left(), area)) {
		    current_pos.move_left();
		}
                break;
            case KEY_RIGHT:
		if (not collides(pieces[current_piece_index].get_current_rotation(), current_pos.next_right(), area)) {
		    current_pos.move_right();
		}
	        break;
	    case KEY_UP:
		if (not collides(*pieces[current_piece_index].next_rotation(), current_pos.get_coordinates(), area)) {
		    pieces[current_piece_index].current_rotation = pieces[current_piece_index].next_rotation();
		}
		break;
	    case KEY_DOWN:
		if (not collides(pieces[current_piece_index].get_current_rotation(), current_pos.next_down(), area)) {
	            current_pos = current_pos.next_down();
		    start = std::chrono::steady_clock::now();
		}
		break;
	    case 'q':
		running = false;
		continue;
	}
	if (since(start).count() > drop_interval) {
	    if (collides(pieces[current_piece_index].get_current_rotation(), current_pos.next_down(), area)) {
	        update_area(pieces[current_piece_index].current_rotation, current_pos.get_coordinates(), area);
		auto completed_lines = get_completed_lines(pieces[current_piece_index].current_rotation->get_line_set(), current_pos, area);
		if (not completed_lines.empty()) {
		    score.update_based_on(completed_lines.size());
		    rebuild_area_with_non_completed_lines(area, completed_lines);
		}
		current_pos = {starting_position};
                current_piece_index = rand() % pieces.size();
		if (collides(pieces[current_piece_index].get_current_rotation(), current_pos.get_coordinates(), area)) {
			running = false;
		}
	        if (drop_interval > MIN_DROP_INTERVAL_LIMIT_MS) {
	            drop_interval -= AFTER_DROP_DECREMENT_MS;
	        }
	    } else {
	        current_pos = current_pos.next_down();
	    }
	    start = std::chrono::steady_clock::now();
	}
	clear();
    }
    if (score.get_score_as_int() > previous_score.get_score_as_int()) {
	write_score_to_binary_file(score.get_score_as_int(), SCORE_FILE);
    }
    endwin();
    return 0;
}

