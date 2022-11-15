#include "../score.hpp"

void init_test() {
    printf("init_test: ");
    const auto EXPECTED_VALUE = "0";
    Score score{};
    if (score.get_score() == EXPECTED_VALUE) {
        printf("PASSED.\n");
        return;
    }
    printf("FAILED. Score should be %s. But was %s.\n", EXPECTED_VALUE, score.get_score().c_str());
}

auto main() -> int {
    printf("*** Score TEST ***)\n\n");

    init_test(); 

    printf("\n");
}

