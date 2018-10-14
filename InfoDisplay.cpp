#include "InfoDisplay.hpp"

InfoDisplay::InfoDisplay(WINDOW *win) : Display(win) {_module = new InfoModule;};
InfoDisplay::~InfoDisplay(void) {delete _module;};

void
InfoDisplay::display() {
    _module->compute();
    int x, y;
    getmaxyx(_win, y, x);
    std::string tmp = _module->getData();
    init_pair(29, COLOR_YELLOW, COLOR_BLACK);
    wattron(_win, COLOR_PAIR(29));
    int l = tmp.length();
    try{
        tmp = tmp.substr(tmp.find("Syst"), l);
        mvwprintw(_win, 2, (x - 11) / 2, "Info Display");
        mvwprintw(_win, 4, 8, tmp.substr(0, tmp.find("Kern") - 7).c_str());
        tmp = tmp.substr(tmp.find("Kern"), tmp.length());
        mvwprintw(_win, 6, 8, tmp.substr(0, tmp.find("Boot") - 7).c_str());
        tmp = tmp.substr(tmp.find("Com"), tmp.length());
        mvwprintw(_win, 8, 8, tmp.substr(0, tmp.find("User") - 7).c_str());
        tmp = tmp.substr(tmp.find("User"), tmp.length());
        mvwprintw(_win, 10, 8, tmp.substr(0, tmp.find("Secu") - 7).c_str());
        tmp = tmp.substr(tmp.find("Tim"), tmp.length());
        mvwprintw(_win, 12, 8, tmp.substr(0, tmp.length() - 1).c_str());
    }
    catch(std::exception &e) {
    }
    wattroff(_win, COLOR_PAIR(29));
    wrefresh(_win);
    box(_win, 0, 0);
    _module->getData().clear();
}

InfoDisplay::InfoDisplay(InfoDisplay const &) {};
InfoDisplay &
InfoDisplay::operator=(InfoDisplay const &) {return *this;};
