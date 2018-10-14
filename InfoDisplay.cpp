#include "InfoDisplay.hpp"

InfoDisplay::InfoDisplay(WINDOW *win) : Display(win) {_module = new InfoModule;};
InfoDisplay::~InfoDisplay(void) {delete _module;};

void
InfoDisplay::display() {
    _module->compute();
    int x, y;
    getmaxyx(_win, y, x);
    std::string tmp = _module->getData();
    mvwprintw(_win, 2, (x - 11) / 2, "Info Display");
    mvwprintw(_win, 4, 7, "System version:");
    mvwprintw(_win, 5, 12, tmp.substr(0, tmp.find(")") + 1).c_str());
    tmp = tmp.substr(tmp.find(")") + 2, tmp.length());
    mvwprintw(_win, 6, 7, "Kernel version:");
    mvwprintw(_win, 7, 12, tmp.substr(0, tmp.find("0") + 1).c_str());
    tmp = tmp.substr(tmp.find("al") + 3, tmp.length());
    mvwprintw(_win, 8, 7, "Computer name:");
    mvwprintw(_win, 9, 12, tmp.substr(0, tmp.find("Dm") - 1).c_str());
    tmp = tmp.substr(tmp.find("Dm"), tmp.length());
    mvwprintw(_win, 10, 7, "User name:");
    mvwprintw(_win, 11, 12, tmp.substr(0, tmp.find("E") - 1).c_str());
    tmp = tmp.substr(tmp.find("Disabled") + 9, tmp.length());
    mvwprintw(_win, 12, 7, "Time since boot:");
    mvwprintw(_win, 13, 12, tmp.substr(0, tmp.length() - 1).c_str());
    wrefresh(_win);
    _module->getData().clear();
}

InfoDisplay::InfoDisplay(InfoDisplay const &) {};
InfoDisplay &
InfoDisplay::operator=(InfoDisplay const &) {return *this;};
