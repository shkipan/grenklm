#include "UserDisplay.hpp"

UserDisplay::UserDisplay(WINDOW *win) : Display(win) {_module = new UserModule;};
UserDisplay::~UserDisplay(void) {delete _module;};

void
UserDisplay::display(){
    _module->compute();
    int x, y;
    getmaxyx(_win, y, x);

    init_pair(24, COLOR_MAGENTA, COLOR_BLACK);
    wattron(_win, COLOR_PAIR(24));
    mvwprintw(_win, 2, (x - 9) / 2, "Kitty Display");
    x = (x - 40) / 2;
    y = 4;
    mvwprintw(_win, y, x, "                \\`*-.");
    mvwprintw(_win, y + 1, x, "                 )  _`-.");
    mvwprintw(_win, y + 2, x, "                .  : `. .");
    mvwprintw(_win, y + 3, x, "                : _   '  \\");
    mvwprintw(_win, y + 4, x, "                ; *` _.   `*-._");
    mvwprintw(_win, y + 5, x, "                `-.-'          `-.");
    mvwprintw(_win, y + 6, x, "                  ;       `       `.");
    mvwprintw(_win, y + 7, x, "                  :.       .        \\");
    mvwprintw(_win, y + 8, x, "                  . \\  .   :   .-'   .");
    mvwprintw(_win, y + 9, x, "                  '  `+.;  ;  '      :");
    mvwprintw(_win, y + 10, x, "                  :  '  |    ;       ;-.");
        mvwprintw(_win, y + 11, x, "                  ; '   : :`-:     _.`* ;");
        mvwprintw(_win, y + 12, x, "         [bug] .*' /  .*' ; .*`- +'  `*'");
        mvwprintw(_win, y + 13, x, "               `*-*   `*-*  `*-*'");
    box(_win, 0, 0);
    wattroff(_win, COLOR_PAIR(24));
    wrefresh(_win);
}

UserDisplay::UserDisplay(UserDisplay const &) {};
UserDisplay &
UserDisplay::operator=(UserDisplay const &) {return *this;};