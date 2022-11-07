#pragma once
#include "piece.hpp"

std::array<Piece, 5> pieces {
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
	}
};
