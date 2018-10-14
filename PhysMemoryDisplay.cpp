#include "PhysMemoryDisplay.hpp"

PhysMemoryDisplay::PhysMemoryDisplay(WINDOW *win) : Display(win) {_module = new PhysMemoryModule;};
PhysMemoryDisplay::~PhysMemoryDisplay(void) {delete _module;};

void
PhysMemoryDisplay::display() {
    std::string tmp;
    _module->generateMemoryData();
    tmp.assign(_module->getOutput());
    int x, y;
    getmaxyx(_win, y, x);
    mvwprintw(_win, 2, (x - 10) / 2, "PhysMemory Display");
    mvwprintw(_win, 9, 5, "                                        ");
    mvwprintw(_win, 4, 2, tmp.substr(0, tmp.length() - 1).c_str());
    wrefresh(_win);
}

PhysMemoryDisplay::PhysMemoryDisplay(PhysMemoryDisplay const &) {};
PhysMemoryDisplay &
PhysMemoryDisplay::operator=(PhysMemoryDisplay const &) {return *this;};
