#include "../main.hpp"

void first_rotation_default_after_creation() {
	printf("first_rotation_default_after_creation: ");
	if (pieces[0].get_current_rotation().coordinates[0].x == 1
			&& pieces[0].get_current_rotation().coordinates[0].y == 0) {
		printf("PASSED.\n");
		return;
	}
	printf("FAILED: Assertion failed.\n");
}

void piece_next_rotation_successfully_set() {
	printf("piece_next_rotation_successfully_set: ");
	pieces[0].current_rotation = pieces[0].next_rotation();
	pieces[0].current_rotation = pieces[0].next_rotation();
	pieces[0].current_rotation = pieces[0].next_rotation();
	if (pieces[0].get_current_rotation().coordinates[0].x == 2
			&& pieces[0].get_current_rotation().coordinates[0].y == 0) {
		printf("PASSED.\n");
		return;
	}
	printf("FAILED: Assertion failed.\n");
}

void when_calling_next_rotation_on_last_element_then_first_is_selected() {
	printf("when_calling_next_rotation_on_last_element_then_first_is_selected: ");

	pieces[0].current_rotation = pieces[0].next_rotation();

	auto x_coordinate = pieces[0].get_current_rotation().coordinates[0].x;
	auto y_coordinate = pieces[0].get_current_rotation().coordinates[0].y;
	const auto x_expected_value = 1;
	const auto y_expected_value = 0;

	if (x_coordinate == x_expected_value && y_coordinate == y_expected_value) {
		printf("PASSED.\n");
		return;
	}
	printf("FAILED: Expected x to be %d and was %d, y to be %d and was %d.\n",
			x_expected_value, x_coordinate, y_expected_value, y_coordinate);
}

void when_calling_previous_rotation_on_first_element_then_last_is_selected() {
	printf("when_calling_previous_rotation_on_first_element_then_last_is_selected: ");

	pieces[0].current_rotation = pieces[0].rotations.cbegin();
	pieces[0].current_rotation = pieces[0].previous_rotation();

	if (pieces[0].get_current_rotation().coordinates[0].x == 2
			&& pieces[0].get_current_rotation().coordinates[0].y == 0) {
		printf("PASSED.\n");
		return;
	}
	printf("FAILED: Assertion failed.\n");
}

void piece_previous_rotation_successfully_set() {
	printf("piece_previous_rotation_successfully_set: ");

	pieces[0].current_rotation = pieces[0].previous_rotation();

	if (pieces[0].get_current_rotation().coordinates[0].x == 0
			&& pieces[0].get_current_rotation().coordinates[0].y == 0) {
		printf("PASSED.\n");
		return;
	}
	printf("FAILED: Assertion failed.\n");
}

void when_on_non_colliding_position_return_false() {
	printf("when_on_non_colliding_position_return_false: ");
	Point position{5, 1};
	const auto area = play_field.substr(1);
	if (not collides(pieces[0].rotations[0], position, area)) {
		printf("PASSED.\n");
		return;
	}
	printf("FAILED: Assertion failed.\n");
}

void when_position_on_very_top_left_do_not_collide() {
	printf("when_position_on_very_top_left_do_not_collide: ");
	Point top_left{0, 1};
	const auto area = play_field.substr(1);
	if (not collides(pieces[0].rotations[0], top_left, area)) {
		printf("PASSED.\n");
		return;
	}
	printf("FAILED: Assertion failed.\n");
}

void when_position_on_very_top_left_collide_with_colliding_rotation() {
	printf("when_position_on_very_top_left_collide_with_colliding_rotation: ");
	Point top_left{0, 1};
	const auto area = play_field.substr(1);
	if (collides(pieces[0].rotations[1], top_left, area)) {
		printf("PASSED.\n");
		return;
	}
	printf("FAILED: Assertion failed.\n");
}

int main() {
	printf("\n*** MAIN TEST ***\n\n");
	first_rotation_default_after_creation();
	piece_next_rotation_successfully_set();
	when_calling_next_rotation_on_last_element_then_first_is_selected();
	when_calling_previous_rotation_on_first_element_then_last_is_selected();
	piece_previous_rotation_successfully_set();
	when_on_non_colliding_position_return_false();
	when_position_on_very_top_left_do_not_collide();
	when_position_on_very_top_left_collide_with_colliding_rotation();
	printf("\n");
	return 0;
}
