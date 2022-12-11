#include "file_ops.hpp"
#include <fstream>

auto is_file_empty(std::ifstream& file) -> bool {
    return file.peek() == std::ifstream::traits_type::eof();
}

auto read_score_from_binary_file(const char* file_path) -> std::optional<int> {
    std::ifstream file (file_path, std::ios::in | std::ios::binary);
    if (not file.is_open()) {
	return std::nullopt;
    }
    if (is_file_empty(file)) {
	return 0;
    }
    int score{0};
    file.read((char*) &score, sizeof(score));
    return score;
}

void write_score_to_binary_file(const int number, const char* file_path) {
    std::ofstream file (file_path, std::ios::out | std::ios::binary);
    if (not file.is_open()) {
	printf("ERROR: write_int_to_binary_file: unable to open file\n");
	return;
    }
    file.write((char*) &number, sizeof(number));
}

