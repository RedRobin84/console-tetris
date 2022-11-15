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

void update_score_test() {
    printf("update_score_test: ");
    const auto EXPECTED_VALUE = "12";
    Score score{};
    score.update_based_on(3);
    score.update_based_on(4);
    score.update_based_on(9);
    if (score.get_score() == EXPECTED_VALUE) {
	printf("PASSED.\n");
	return;
    }
    printf("FAILED. Score should be %s. But was %s.\n", EXPECTED_VALUE, score.get_score().c_str());
}

auto main() -> int {
    printf("*** Score TEST ***\n\n");

    init_test(); 
    update_score_test();

    printf("\n");
}

