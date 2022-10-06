#include <ncurses.h>
#include "../main.hpp"

Piece L {
	std::array<Rotation, ROTATION_NUMBER>{
		std::array<Point, PIECE_POINT_NUMBER>{Point{1, 0}, Point{1, 1}, Point{1, 2}, Point{2, 2}},
		std::array<Point, PIECE_POINT_NUMBER>{Point{0, 2}, Point{0, 1}, Point{1, 1}, Point{2, 1}},
		std::array<Point, PIECE_POINT_NUMBER>{Point{0, 0}, Point{1, 0}, Point{1, 1}, Point{1, 2}},
		std::array<Point, PIECE_POINT_NUMBER>{Point{0, 1}, Point{1, 1}, Point{2, 1}, Point{2, 0}}
	}
};

void first_rotation_default_after_creation() {
	printf("first_rotation_default_after_creation: ");
	if (L.current_rotation->coordinates[0].x == 1 && L.current_rotation->coordinates[0].y == 0) {
		printf("PASSED.\n");
		return;
	}
	printf("FAILED: Assertion failed.\n");
}

void piece_next_rotation_successfully_set() {
	printf("piece_next_rotation_successfully_set: ");
	L.nextRotation();
	L.nextRotation();
	L.nextRotation();
	if (L.current_rotation->coordinates[0].x == 0 && L.current_rotation->coordinates[0].y == 1) {
		printf("PASSED.\n");
		return;
	}
	printf("FAILED: Assertion failed.\n");
}

//Add test for edge case - when calling nextRotation() on last element

int main() {
	first_rotation_default_after_creation();
	piece_next_rotation_successfully_set();
	return 0;
}
