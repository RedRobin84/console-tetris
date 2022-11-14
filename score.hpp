#pragma once

#include "point.hpp"

#include <string>

const int DEFAULT_SCORE {0};
const Point SCORE_POS {15, 2};

class Score {
    private:
	int score = DEFAULT_SCORE;
	std::string score_to_display = std::to_string(DEFAULT_SCORE);
    public:
	inline const std::string& get_score() {
	    return score_to_display;
	}

        inline void update_based_on(const size_t nr_of_completed_lines) {
	    switch(nr_of_completed_lines) {
	        case 1: score += 1;
		break;
		case 2: score += 3;
		break;
	        case 3: score += 5;
		break;
		case 4: score += 7;
		break;
		default: score += 0;
	    }
	    score_to_display = std::to_string(score);
	}
};
