#include "NetDisplay.hpp"

NetDisplay::NetDisplay(WINDOW *win) : Display(win) {_module = new NetModule;};
NetDisplay::~NetDisplay(void) {delete _module;};

void
NetDisplay::display() {
    _module->compute();
    int x, y;
        try {
    getmaxyx(_win, y, x);
    std::string tmp = _module->getData();
    init_pair(21, COLOR_RED, COLOR_BLACK);
    wattron(_win, COLOR_PAIR(21));
    mvwprintw(_win, 2, (x - 10) / 2, "Net Display");
    mvwprintw(_win, 4, 2, tmp.substr(0, tmp.find("in")).c_str());
    mvwprintw(_win, 5, 2, tmp.substr(tmp.find("in") + 3, tmp.length() - tmp.find("in") - 7).c_str());
    box(_win, 0, 0);
    wattroff(_win, COLOR_PAIR(21));

    int x = stof(tmp) * 40 / 4000000;
    init_pair(72, COLOR_BLACK, COLOR_BLACK);
    wattron(_win, COLOR_PAIR(72));
    mvwprintw(_win, 10, 5, "%50s", "1");
    wattroff(_win, COLOR_PAIR(72));
    init_pair(52, COLOR_RED, COLOR_RED);
    wattron(_win, COLOR_PAIR(52));
    mvwprintw(_win, 10, 5, "%*s", x, "1");
    wattroff(_win, COLOR_PAIR(52));
    }
    catch (std::exception & e){

    }
    wrefresh(_win);
    _module->getData().clear();
}

NetDisplay::NetDisplay(NetDisplay const &) {};
NetDisplay &
NetDisplay::operator=(NetDisplay const &) {return *this;};
