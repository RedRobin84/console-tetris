#include <stdio.h>
#include <ncurses.h>
#include <chrono>
#include <thread>

int main() {
     const char one[]  = R"(
 XX  
  X
  X
  X
  X
)";
    const char two[] = " XXX \n   X \n XXX \n X   \n XXX \n";
    const char three[] = " XXX \n   X \n XXX \n   X \n XXX \n";

    initscr();
    printw(one);
    refresh();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000)); 
    clear();
    printw(two);
    refresh();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000)); 
    clear();
    printw(three);
    refresh();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000)); 
    endwin();
    return 0;
}
