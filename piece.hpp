#pragma once

#include "rotation.hpp"

const int ROTATION_NUMBER = 4;

struct Piece
{
	const std::array<const Rotation, ROTATION_NUMBER> rotations;
	const Rotation* current_rotation = rotations.cbegin();

	const Rotation* next_rotation() const {
		const auto next_element = std::next(current_rotation);
		if (next_element == rotations.cend()) {
			return rotations.cbegin();
		}
		return next_element;
	}

	const void set_next_rotation() {
		current_rotation = next_rotation();
	}

	const void set_previous_rotation() {
		current_rotation = previous_rotation();
	}

	const Rotation* previous_rotation() const {
		if (current_rotation == rotations.cbegin()) {
			return &rotations.back();
		}
		return std::prev(current_rotation);
	}

	const Rotation get_current_rotation() const {
		return *current_rotation;
	}
};

