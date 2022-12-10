#pragma once
#include <string>

auto read_score_from_binary_file(const char* file_path) -> const int;

void write_score_to_binary_file(const int number, const char* file_path);

