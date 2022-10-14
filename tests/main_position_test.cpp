#include "../main.hpp"

void when_default_ctr_used_top_center_is_used() {
	printf("when_default_ctr_used_top_center_is_used: \n");
	auto default_position = Position();
	if (default_position.get_x() == 5 && default_position.get_y() == 1) {
		printf("PASSED.\n");
		return;
	}
	printf("FAILED. Assertion failed.");
}

int main() {
	printf("*** Position class TEST ***\n\n");
	when_default_ctr_used_top_center_is_used();
	printf("\n");
	return 0;
}

