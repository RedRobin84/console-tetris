#include "../main.hpp"

void get_area_index_success() {
   printf("get_area_index_success: ");
   const Point upper_left_corner {0, 1};
   const auto area = play_field.substr(1);
   const auto index = get_area_index(L.current_rotation->coordinates[0], upper_left_corner);
   if (index == 27)  {
       printf("PASSED. \n");
       return;
   }
   printf("FAILED. Index is %d insted of 28.\n", index);
}

void get_char_at_index() {
   printf("get_char_at_index: ");
   const Point upper_left_corner {0, 1};
   const auto area = play_field.substr(1);
   const auto index = get_area_index(L.current_rotation->coordinates[0], upper_left_corner);
   if (area[index] == ' ')  {
       printf("PASSED. \n");
       return;
   }
   printf("FAILED. Char at index %d is %c insted of \" \".\n", index, area[index]);
}

void successfully_written_char() {
    printf("successfully_written_char: ");
    const Point upper_left_corner {0, 1};
    auto area = play_field.substr(1);
    update_area(L.current_rotation, upper_left_corner, area);  
    if (area[27] == '0') {
	printf("PASSED.\n");
	return;
    }
    printf("FAILED: Char at index %d should be O but was %c.\n", 27, area[27]);
}

int main() {
    printf("*** Area related logic TEST ***\n\n");
    get_area_index_success();
    successfully_written_char();
    get_char_at_index();
    printf("\n");
    return 0;
}
