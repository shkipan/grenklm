#include "NetDisplay.hpp"

NetDisplay::NetDisplay(WINDOW *win) : Display(win) {_module = new NetModule;};
NetDisplay::~NetDisplay(void) {delete _module;};

void
NetDisplay::display() {
    _module->compute();
    box(_win, 0, 0);
    mvwprintw(_win, 2, 2, "NetDisplay");
    std::string tmp = _module->getData().substr(_module->getData().find("s: ") + 3,
        _module->getData().length() - 3 - (_module->getData().find("n,") + 2 - _module->getData().find("s: ") + 3));
    tmp = tmp.substr(tmp.find("s: ") + 3,
        tmp.length() - (tmp.find("n,") + 2 - tmp.find("s: ") + 3));
    mvwprintw(_win, 3, 2, tmp.c_str());
    mvwprintw(_win, 4, 2, _module->getData().substr(_module->getData().find("n,") + 3,
        _module->getData().length() - 5 - _module->getData().find("n,") - 3).c_str());
    wrefresh(_win);
}

NetDisplay::NetDisplay(NetDisplay const &) {};
NetDisplay &
NetDisplay::operator=(NetDisplay const &) {return *this;};
