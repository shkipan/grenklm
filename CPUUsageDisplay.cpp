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
    try {
    mvwprintw(_win, 2, (x - 16) / 2, "CPU Usage Display");
    mvwprintw(_win, 4, 2, tmp.substr(0, tmp.find("CPU Core") - 1).c_str());
    tmp = tmp.substr(tmp.find("CPU Core"), tmp.length());
    mvwprintw(_win, 5, 2, tmp.substr(0, tmp.find("CPU usage") - 1).c_str());
    tmp = tmp.substr(tmp.find("e: ") + 3, tmp.length() - tmp.find("e: ") + 3);
    mvwprintw(_win, 7, 2, "CPU usage: ");
    mvwprintw(_win, 8, 5, "                       ");
    init_pair(42, COLOR_RED, COLOR_BLACK);
    wattron(_win, COLOR_PAIR(42));
    mvwprintw(_win, 8, 5, "%s", tmp.substr(0, tmp.find(",")).c_str());
    wattroff(_win, COLOR_PAIR(42));

    int x = stof(tmp) * 40 / 100;
    init_pair(62, COLOR_BLACK, COLOR_BLACK);
    wattron(_win, COLOR_PAIR(62));
    mvwprintw(_win, 12, 5, "%50s", "1");
    wattroff(_win, COLOR_PAIR(62));
    init_pair(52, COLOR_RED, COLOR_RED);
    wattron(_win, COLOR_PAIR(52));
    mvwprintw(_win, 12, 5, "%*s", x, "1");
    wattroff(_win, COLOR_PAIR(52));

    tmp = tmp.substr(tmp.find(",") + 2, tmp.length());
    mvwprintw(_win, 9, 5, "                       ");
    init_pair(43, COLOR_YELLOW, COLOR_BLACK);
    wattron(_win, COLOR_PAIR(43));
    mvwprintw(_win, 9, 5, "%s", tmp.substr(0, tmp.find(",")).c_str());
    wattroff(_win, COLOR_PAIR(43));

    x = stof(tmp) * 40 / 100;
    init_pair(63, COLOR_BLACK, COLOR_BLACK);
    wattron(_win, COLOR_PAIR(63));
    mvwprintw(_win, 13, 5, "%50s", "1");
    wattroff(_win, COLOR_PAIR(63));
    init_pair(53, COLOR_YELLOW, COLOR_YELLOW);
    wattron(_win, COLOR_PAIR(53));
    mvwprintw(_win, 13, 5, "%*s", x, "1");
    wattroff(_win, COLOR_PAIR(53));

    tmp = tmp.substr(tmp.find(",") + 2, tmp.length());
    mvwprintw(_win, 10, 5, "                       ");
    init_pair(44, COLOR_GREEN, COLOR_BLACK);
    wattron(_win, COLOR_PAIR(44));
    mvwprintw(_win, 10, 5, "%s", tmp.substr(0, tmp.length() - 1).c_str());
    wattroff(_win, COLOR_PAIR(44));

    x = stof(tmp) * 40 / 100;
    init_pair(64, COLOR_BLACK, COLOR_BLACK);
    wattron(_win, COLOR_PAIR(64));
    mvwprintw(_win, 14, 5, "%50s", "1");
    wattroff(_win, COLOR_PAIR(64));
    init_pair(54, COLOR_GREEN, COLOR_GREEN);
    wattron(_win, COLOR_PAIR(54));
    mvwprintw(_win, 14, 5, "%*s", x, "1");
    wattroff(_win, COLOR_PAIR(54));
    box(_win, 0, 0);
    }
    catch (std::exception & e){

    }
    wrefresh(_win);
}

CPUUsageDisplay::CPUUsageDisplay(CPUUsageDisplay const &) {};
CPUUsageDisplay &
CPUUsageDisplay::operator=(CPUUsageDisplay const &) {return *this;};
