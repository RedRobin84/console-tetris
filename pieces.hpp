#pragma once
#include "piece.hpp"

/*
 * L
 * J
 * T
 * square
 * I
 * Z
 * S
*/
const std::size_t NR_OF_PIECES = 7;

std::array<Piece, NR_OF_PIECES> pieces {
	Piece{
		Rotation{Point{1, 0}, Point{1, 1}, Point{1, 2}, Point{2, 2}},
		Rotation{Point{0, 1}, Point{1, 1}, Point{2, 1}, Point{0, 2}},
		Rotation{Point{0, 0}, Point{1, 0}, Point{1, 1}, Point{1, 2}},
		Rotation{Point{2, 0}, Point{0, 1}, Point{1, 1}, Point{2, 1}}
	},

	Piece{
		Rotation{Point{1, 0}, Point{1, 1}, Point{0, 2}, Point{1, 2}},
		Rotation{Point{0, 0}, Point{0, 1}, Point{1, 1}, Point{2, 1}},
		Rotation{Point{1, 0}, Point{2, 0}, Point{1, 1}, Point{1, 2}},
		Rotation{Point{0, 1}, Point{1, 1}, Point{2, 1}, Point{2, 2}}
	},

	Piece{
		Rotation{Point{1, 0}, Point{0, 1}, Point{1, 1}, Point{2, 1}},
		Rotation{Point{1, 0}, Point{1, 1}, Point{2, 1}, Point{1, 2}},
		Rotation{Point{0, 1}, Point{1, 1}, Point{2, 1}, Point{1, 2}},
		Rotation{Point{1, 0}, Point{0, 1}, Point{1, 1}, Point{1, 2}}
	},

	Piece{
		Rotation{Point{0, 0}, Point{1, 0}, Point{0, 1}, Point{1, 1}},
		Rotation{Point{0, 0}, Point{1, 0}, Point{0, 1}, Point{1, 1}},
		Rotation{Point{0, 0}, Point{1, 0}, Point{0, 1}, Point{1, 1}},
		Rotation{Point{0, 0}, Point{1, 0}, Point{0, 1}, Point{1, 1}}
	},

	Piece{
		Rotation{Point{0, 1}, Point{1, 1}, Point{2, 1}, Point{3, 1}},
		Rotation{Point{2, 0}, Point{2, 1}, Point{2, 2}, Point{2, 3}},
		Rotation{Point{0, 2}, Point{1, 2}, Point{2, 2}, Point{3, 2}},
		Rotation{Point{0, 0}, Point{0, 1}, Point{0, 2}, Point{0, 3}}
	},

	Piece{
		Rotation{Point{0, 0}, Point{1, 0}, Point{1, 1}, Point{2, 1}},
		Rotation{Point{2, 0}, Point{2, 1}, Point{1, 1}, Point{1, 2}},
		Rotation{Point{0, 1}, Point{1, 1}, Point{1, 2}, Point{2, 2}},
		Rotation{Point{1, 0}, Point{0, 1}, Point{1, 1}, Point{0, 2}}
	},

	Piece{
		Rotation{Point{1, 0}, Point{2, 0}, Point{1, 1}, Point{0, 1}},
		Rotation{Point{1, 0}, Point{1, 1}, Point{2, 1}, Point{2, 2}},
		Rotation{Point{1, 1}, Point{2, 1}, Point{0, 2}, Point{1, 2}},
		Rotation{Point{0, 0}, Point{0, 1}, Point{1, 1}, Point{1, 2}}
	}
};
