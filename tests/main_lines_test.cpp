#include "../main.hpp"

void return_unique_lines_for_rotation() {
    printf("return_unique_lines_for_rotation: ");
    const auto line_set = L.rotations[1].get_line_set();
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

int main() {
    printf("*** Area lines TEST ***\n\n");
    return_unique_lines_for_rotation();
    get_index_of_first_line_measuring();
    get_line_begin_value_should_match_T_char();
    get_line_end_value_should_match_T_char();
    line_is_completed();
    line_is_not_completed();
    printf("\n");
    return 0;
}
