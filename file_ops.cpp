#include "file_ops.hpp"
#include <fstream>

auto read_score_from_binary_file(const char* file_path) -> const int {
    int score{0};
    std::ifstream file (file_path, std::ios::in | std::ios::binary);
    if (not file.is_open()) {
	printf("ERROR: read_score_from_binary_file: unable to open file\n");
	return score;
    }
    if (file.peek() == std::ifstream::traits_type::eof()) {
	printf("read_score_from_binary_file: Empty file, returning default score\n");
	file.close();
	return score;
    }
    file.read((char*) &score, sizeof(score));
    file.close();
    return score;
}

void write_score_to_binary_file(const int number, const char* file_path) {
	std::ofstream file (file_path, std::ios::out | std::ios::binary);
	if (not file.is_open()) {
	    printf("ERROR: write_int_to_binary_file: unable to open file\n");
	    return;
	}
	file.write((char*) &number, sizeof(number));
	file.close();
}

