#include "../main.hpp"

void when_default_ctr_used_top_center_is_used() {
    printf("when_default_ctr_used_top_center_is_used: ");
    auto default_position = Position();
    if (default_position.get_x() == 5 && default_position.get_y() == 1) {
	printf("PASSED.\n");
	return;
    }
    printf("FAILED. Assertion failed.");
}

void when_move_left_to_legal_position__then_move_to_that_position() {
    printf("when_move_left_to_legal_position__then_move_to_that_position: ");
    auto default_position = Position();
    default_position.move_left();
    if (default_position.get_x() == 4 && default_position.get_y() == 1) {
	printf("PASSED.\n");
	return;
    }
    printf("FAILED. Assertion failed.");
}


void when_move_left_to_illegal_position__then_keep_position() {
    printf("when_move_left_to_illegal_position__then_keep_position: ");
    Position top_left_position {UPPER_LEFT_BORDER};
    top_left_position.move_left();
    if (top_left_position.get_x() == 0 && top_left_position.get_y() == 1) {
	printf("PASSED.\n");
	return;
    }
    printf("FAILED. Assertion failed.");
}

int main() {
    printf("*** Position class TEST ***\n\n");
    when_default_ctr_used_top_center_is_used();
    when_move_left_to_legal_position__then_move_to_that_position();
    when_move_left_to_illegal_position__then_keep_position();
    printf("\n");
    return 0;
}

