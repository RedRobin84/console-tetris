#include "../file_ops.hpp"

#include <filesystem>
#include <fstream>


namespace read_score {
    void when_file_doesnt_exist__then_return_empty_optional() {
        printf("when_file_doesnt_exist__then_return_empty_optional: ");
	std::optional<int> score = read_score_from_binary_file("test.bin");
	if (not score.has_value()) {
	    printf("PASSED.\n");
	    return;
	}
	printf("FAILED. Score should be empty, but was %d\n", score.value());
    }

    void when_file_empty__then_return_empty_optional() {
	printf("when_file_empty__then_return_empty_optional: ");
	std::ofstream file("test.bin", std::ios::out | std::ios::binary);
	std::optional<int> score = read_score_from_binary_file("test.bin");
	if (score.value() == 0) {
	    printf("PASSED.\n");
	    return;
	}
	printf("FAILED. Score should be 0, but was %d\n", score.value());
    }

} // namespace read_score

namespace write_score {
    void write_score_to_binary_file__then_file_contains_score() {
	printf("write_score_to_binary_file__then_file_contains_score: ");
	write_score_to_binary_file(42, "test.bin");
	std::optional<int> score = read_score_from_binary_file("test.bin");
	if (score.value() == 42) {
	    printf("PASSED.\n");
	    return;
	}
	printf("FAILED. Score should be 42, but was %d\n", score.value());
    }
} // namespace write_score

auto main() -> int {
    printf("*** File ops TEST ***\n\n");
    try {
	if (std::filesystem::exists("test.bin")) {
    	    std::filesystem::remove("test.bin");
	}
    } catch(const std::filesystem::filesystem_error& err) {
	printf("Error in filesystem: %s", err.what());
    	return 1;
    }
    read_score::when_file_doesnt_exist__then_return_empty_optional();
    read_score::when_file_empty__then_return_empty_optional();
    write_score::write_score_to_binary_file__then_file_contains_score();
    printf("\n");
    return 0;
}

