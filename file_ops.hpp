#pragma once
#include <string>
#include <optional>

auto read_score_from_binary_file(const char* file_path) -> std::optional<int>;

void write_score_to_binary_file(const int number, const char* file_path);

