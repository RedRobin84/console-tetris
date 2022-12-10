#include "../file_ops.hpp"

#include <filesystem>

auto main() -> int {
    try {
	if (std::filesystem::exists("test.bin")) {
    	    std::filesystem::remove("test.bin");
	}
    } catch(const std::filesystem::filesystem_error& err) {
	printf("Error in filesystem: %s", err.what());
    	return 1;
    }
}
