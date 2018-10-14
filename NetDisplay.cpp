#include "NetDisplay.hpp"

NetDisplay::NetDisplay(WINDOW *win) : Display(win) {_module = new NetModule;};
NetDisplay::~NetDisplay(void) {delete _module;};

void
NetDisplay::display() {
    _module->compute();
    int x, y;
    getmaxyx(_win, y, x);
    mvwprintw(_win, 2, (x - 10) / 2, "Net Display");
    std::string tmp = _module->getData();
    mvwprintw(_win, 4, 2, tmp.substr(0, tmp.find("in")).c_str());
    mvwprintw(_win, 5, 2, tmp.substr(tmp.find("in") + 3, tmp.length() - tmp.find("in") - 7).c_str());
    wrefresh(_win);
    _module->getData().clear();
}

NetDisplay::NetDisplay(NetDisplay const &) {};
NetDisplay &
NetDisplay::operator=(NetDisplay const &) {return *this;};
