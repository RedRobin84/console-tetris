#include "../main.hpp"

void first_rotation_default_after_creation() {
	printf("first_rotation_default_after_creation: ");
	if (L.get_current_rotation().coordinates[0].x == 1 
			&& L.get_current_rotation().coordinates[0].y == 0) {
		printf("PASSED.\n");
		return;
	}
	printf("FAILED: Assertion failed.\n");
}

void piece_next_rotation_successfully_set() {
	printf("piece_next_rotation_successfully_set: ");
	L.current_rotation = L.next_rotation();
	L.current_rotation = L.next_rotation();
	L.current_rotation = L.next_rotation();
	if (L.get_current_rotation().coordinates[0].x == 0 
			&& L.get_current_rotation().coordinates[0].y == 1) {
		printf("PASSED.\n");
		return;
	}
	printf("FAILED: Assertion failed.\n");
}

void when_calling_next_rotation_on_last_element_then_first_is_selected() {
	printf("when_calling_next_rotation_on_last_element_then_first_is_selected: ");

	L.current_rotation = L.next_rotation();

	if (L.get_current_rotation().coordinates[0].x == 1 
			&& L.get_current_rotation().coordinates[0].y == 0) {
		printf("PASSED.\n");
		return;
	}
	printf("FAILED: Assertion failed.\n");
}

void when_calling_previous_rotation_on_first_element_then_last_is_selected() {
	printf("when_calling_previous_rotation_on_first_element_then_last_is_selected(): ");

	L.current_rotation = L.previous_rotation();

	if (L.get_current_rotation().coordinates[0].x == 0 
			&& L.get_current_rotation().coordinates[0].y == 1) {
		printf("PASSED.\n");
		return;
	}
	printf("FAILED: Assertion failed.\n");
}

void piece_previous_rotation_successfully_set() {
	printf("piece_previous_rotation_successfully_set: ");

	L.current_rotation = L.previous_rotation();

	if (L.get_current_rotation().coordinates[0].x == 0 
			&& L.get_current_rotation().coordinates[0].y == 0) {
		printf("PASSED.\n");
		return;
	}
	printf("FAILED: Assertion failed.\n");
}

void when_on_non_colliding_position_return_false() {
	printf("when_on_non_colliding_position_return_false: ");
	Position position({5, 1});
	const auto area = play_field.substr(1);
	if (not collides(L.rotations[0], position, area)) {
		printf("PASSED.\n");
		return;
	}
	printf("FAILED: Assertion failed.\n");
}

void when_position_on_very_top_left_do_not_collide() {
	printf("when_position_on_very_top_left_do_not_collide: ");
	Position top_left({0, 1});
	const auto area = play_field.substr(1);
	if (not collides(L.rotations[0], top_left, area)) {
		printf("PASSED.\n");
		return;
	}
	printf("FAILED: Assertion failed.\n");
}

void when_position_on_very_top_left_collide_with_colliding_rotation() {
	printf("when_position_on_very_top_left_collide_with_colliding_rotation: ");
	Position top_left({0, 1});
	const auto area = play_field.substr(1);
	if (collides(L.rotations[1], top_left, area)) {
		printf("PASSED.\n");
		return;
	}
	printf("FAILED: Assertion failed.\n");
}

int main() {
	printf("*** MAIN TEST ***\n\n");
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
