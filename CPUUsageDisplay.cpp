#include "CPUUsageDisplay.hpp"
#include <fstream>
CPUUsageDisplay::CPUUsageDisplay(WINDOW *win) : Display(win) {_module = new CPUUsageModule;};
CPUUsageDisplay::~CPUUsageDisplay(void) {delete _module;};

void
CPUUsageDisplay::display() {
    std::string tmp;
    _module->tick();
    tmp.assign(_module->getOutput());

    int x, y;
    getmaxyx(_win, y, x);
    mvwprintw(_win, 2, (x - 16) / 2, "CPU Usage Display");

    mvwprintw(_win, 4, 2, tmp.substr(0, tmp.find("CPU Core") - 1).c_str());
    tmp = tmp.substr(tmp.find("CPU Core"), tmp.length());
    mvwprintw(_win, 5, 2, tmp.substr(0, tmp.find("CPU usage") - 1).c_str());
    tmp = tmp.substr(tmp.find("e: ") + 3, tmp.length() - tmp.find("e: ") + 3);
    mvwprintw(_win, 6, 2, "CPU usage: ");
    mvwprintw(_win, 7, 5, "                       ");
    mvwprintw(_win, 7, 5, "%s", tmp.substr(0, tmp.find(",")).c_str());
    tmp = tmp.substr(tmp.find(",") + 2, tmp.length());
    mvwprintw(_win, 8, 5, "                       ");
    mvwprintw(_win, 8, 5, "%s", tmp.substr(0, tmp.find(",")).c_str());
    tmp = tmp.substr(tmp.find(",") + 2, tmp.length());
    mvwprintw(_win, 9, 5, "                       ");
    mvwprintw(_win, 9, 5, "%s", tmp.substr(0, tmp.length() - 1).c_str());
    wrefresh(_win);
}

CPUUsageDisplay::CPUUsageDisplay(CPUUsageDisplay const &) {};
CPUUsageDisplay &
CPUUsageDisplay::operator=(CPUUsageDisplay const &) {return *this;};
