#include "../main.hpp"

void return_unique_lines_for_rotation() {
    printf("return_unique_lines_for_rotation: ");
    const auto line_set = pieces[0].rotations[1].get_line_set();
    const auto set_size = line_set.size();
    const bool line_one_found = line_set.find(1) != line_set.end();
    const bool line_two_found = line_set.find(2) != line_set.end();
    if (set_size == 2 and line_one_found and line_two_found) {
        printf("PASSED. \n");
        return;
    }
    printf("FAILED. Output size: %lu, line 1 found: %d, line 2 found: %d\n", set_size, line_one_found, line_two_found);
}

void get_index_of_first_line_measuring() {
    printf("get_index_of_first_line_measuring: ");

const std::string play_field = R"(
XXXXXXXXXXXXXXXXXXXXXXXXX
XT         X    Score   X
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
    const auto first_line_start_index = get_line_starting_index(1);
    if (first_line_start_index == 27 and play_field.substr(1)[first_line_start_index] == 'T') {
        printf("PASSED. \n");
        return;
    }
    printf("FAILED: Starting index for 1st line %d, instead of 27.\n", first_line_start_index);
}

void get_line_begin_value_should_match_T_char() {
    printf("get_line_begin_value_should_match_T_char: ");

const std::string play_field = R"(
XXXXXXXXXXXXXXXXXXXXXXXXX
X          X    Score   X
X          X            X
XT         X            X
X          X            X
X          X            X
X          X            X
X          X            X
X          X            X
X          X            X
X          X            X
XXXXXXXXXXXXXXXXXXXXXXXXX
)";
    auto third_line_begin = get_nth_line_begin(3, play_field.substr(1));
    if (*third_line_begin == 'T') {
        printf("PASSED. \n");
        return;
    }
    printf("FAILED. Char on beginning of the line should be 'T' but was '%c'.\n", *third_line_begin);
}

void get_line_end_value_should_match_T_char() {
    printf("get_line_end_value_should_match_T_char: ");

const std::string play_field = R"(
XXXXXXXXXXXXXXXXXXXXXXXXX
X         TX    Score   X
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
    const auto first_line_begin = get_nth_line_begin(1, play_field.substr(1));
    const auto first_line_end = get_nth_line_end(first_line_begin);
    if (*first_line_end == 'X' and *(first_line_end - 1) == 'T') {
        printf("PASSED.\n");
        return;
    }
    printf("FAILED. Line end should be 'X' and was '%c'. Last char of the line should be 'T' and was '%c'.\n", *first_line_end, *(first_line_end - 1));
}

void line_is_completed() {
    printf("line_is_completed: ");

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
X0000000000X            X
XXXXXXXXXXXXXXXXXXXXXXXXX
)";
    const bool line_completed = is_line_completed(10, play_field.substr(1));
    if (line_completed) {
        printf("PASSED.\n");
        return;
    }
    printf("FAILED. Line is not completed.\n");
}

void line_is_not_completed() {
    printf("line_is_not_completed: ");

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
X000 000000X            X
XXXXXXXXXXXXXXXXXXXXXXXXX
)";
    const bool line_completed = is_line_completed(10, play_field.substr(1));
    if (not line_completed) {
        printf("PASSED.\n");
        return;
    }
    printf("FAILED. Line is completed.\n");
}

void get_completed_lines_test() {
    printf("get_completed_lines_test: ");

const std::string play_field = R"(
XXXXXXXXXXXXXXXXXXXXXXXXX
X          X    Score   X
X          X            X
X          X            X
X          X            X
X          X            X
X          X            X
X          X            X
X   0      X            X
X0000000000X            X
X0000000000X            X
XXXXXXXXXXXXXXXXXXXXXXXXX
)";
    Position pos {{3, 8}};
    const std::set<int> rotation_lines = pieces[0].rotations[0].get_line_set();
    std::set<int> completed_lines = get_completed_lines(rotation_lines, pos, play_field.substr(1));
    if (completed_lines.size() == 2
            and completed_lines.find(9) != completed_lines.end()
            and completed_lines.find(10) != completed_lines.end()) {
        printf("PASSED.\n");
        return;
    }
    printf("FAILED. Set size (%lu) or/and elements do not match.\n", completed_lines.size());
}

void move_line_test() {
    printf("move_line_test: ");

std::string area_before = R"(
XXXXXXXXXXXXXXXXXXXXXXXXX
X          X    Score   X
X          X            X
X          X            X
X          X            X
X          X            X
X          X            X
X          X            X
X          X            X
X0000000000X            X
X          X            X
XXXXXXXXXXXXXXXXXXXXXXXXX
)";

std::string area_after = R"(
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
X0000000000X            X
XXXXXXXXXXXXXXXXXXXXXXXXX
)";
    auto area_before_formatted = area_before.substr(1);
    auto area_after_formatted = area_after.substr(1);
    auto ninth_line_begin = get_nth_line_begin(9, area_before_formatted); 
    auto tenth_line_begin = get_nth_line_begin(10, area_before_formatted); 
    move_line(ninth_line_begin, tenth_line_begin);
    if (area_before_formatted == area_after_formatted) {
        printf("PASSED.\n");
	return;
    }
    printf("FAILED. Expected area\n%s\n but is\n%s\n.", area_before_formatted.c_str(), area_after_formatted.c_str());
}

void line_empty_test() {
    printf("line_empty_test: ");
    std::string area_formatted = play_field.substr(1);
    auto first_line_begin = get_nth_line_begin(1, area_formatted);
    if (line_empty(first_line_begin)) {
	printf("PASSED.\n");
	return;
    }
    printf("FAILED. First line is not empty\n");
}

void rebuild_area_test() {
printf("rebuild_area_test: ");
std::string area_before = R"(
XXXXXXXXXXXXXXXXXXXXXXXXX
X          X    Score   X
X          X            X
X          X            X
X          X            X
X          X            X
X          X            X
X     0    X            X
X0000000000X            X
X0000000000X            X
X00 0000000X            X
XXXXXXXXXXXXXXXXXXXXXXXXX
)";

std::string area_after = R"(
XXXXXXXXXXXXXXXXXXXXXXXXX
X          X    Score   X
X          X            X
X          X            X
X          X            X
X          X            X
X          X            X
X          X            X
X          X            X
X     0    X            X
X00 0000000X            X
XXXXXXXXXXXXXXXXXXXXXXXXX
)";
    std::string area_before_formatted = area_before.substr(1);
    std::string area_after_formatted = area_after.substr(1);
    std::set<int> completed_lines {8, 9};
    rebuild_area_with_non_completed_lines(area_before_formatted, completed_lines);
    if (area_before_formatted == area_after_formatted) {
	printf("PASSED.\n");
	return;
    }
    printf("FAILED. Expected area\n%s\n but is\n%s\n.", area_before_formatted.c_str(), area_after_formatted.c_str());
}

int main() {
    printf("*** Area lines TEST ***\n\n");
    return_unique_lines_for_rotation();
    get_index_of_first_line_measuring();
    get_line_begin_value_should_match_T_char();
    get_line_end_value_should_match_T_char();
    line_is_completed();
    line_is_not_completed();
    get_completed_lines_test();
    line_empty_test();
    move_line_test();
    rebuild_area_test();
    printf("\n");
    return 0;
}
