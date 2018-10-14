#include "NetDisplay.hpp"

NetDisplay::NetDisplay(WINDOW *win) : Display(win) {_module = new NetModule;};
NetDisplay::~NetDisplay(void) {delete _module;};

void
NetDisplay::display() {
    _module->compute();
    int x, y;
    getmaxyx(_win, y, x);
    std::string tmp = _module->getData();
    init_pair(21, COLOR_RED, COLOR_BLACK);
    wattron(_win, COLOR_PAIR(21));
    mvwprintw(_win, 2, (x - 10) / 2, "Net Display");
    mvwprintw(_win, 4, 2, tmp.substr(0, tmp.find("in")).c_str());
    mvwprintw(_win, 5, 2, tmp.substr(tmp.find("in") + 3, tmp.length() - tmp.find("in") - 7).c_str());
    wattroff(_win, COLOR_PAIR(21));
    wrefresh(_win);
    _module->getData().clear();
}

NetDisplay::NetDisplay(NetDisplay const &) {};
NetDisplay &
NetDisplay::operator=(NetDisplay const &) {return *this;};
