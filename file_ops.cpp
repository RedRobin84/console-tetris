#include "file_ops.hpp"
#include <fstream>

auto read_int_from_binary_file(const char* file_path) -> const int {
    std::fstream file (file_path, std::ios::in | std::ios::binary | std::ios::ate);
    if (not file.good()) {
	file.open(file_path, std::ios::in | std::ios::binary | std::ios::trunc);
	file.close();
	return 0;
    }
    if (file.peek() == std::ifstream::traits_type::eof()) {
	return 0;
    }
    int score{};
    if (file.is_open()) {
	file.read((char*) &score, sizeof(score));
    }
    file.close();
    return score;
}

void write_int_to_binary_file(const int number, const char* file_path) {
	std::fstream file (file_path, std::ios::out | std::ios::binary | std::ios::trunc);
	if (file.is_open()) {
	    file.write((char*) &number, sizeof(number));
	}
	file.close();
}

