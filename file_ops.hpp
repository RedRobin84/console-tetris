#pragma once
#include <string>

auto read_int_from_binary_file(const char* file_path) -> const int;

void write_int_to_binary_file(const int number, const char* file_path);

