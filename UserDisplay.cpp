#include "UserDisplay.hpp"

UserDisplay::UserDisplay(WINDOW *win) : Display(win) {_module = new UserModule;};
UserDisplay::~UserDisplay(void) {delete _module;};

void
UserDisplay::display(){
    _module->compute();
    int x, y;
    getmaxyx(_win, y, x);
    mvwprintw(_win, 2, (x - 9) / 2, "Pony Display");
    x = (x - 40) / 2;
    y = (y - 11) / 2;
    mvwprintw(_win, y, x, "                    ~~%%%%%%%%%%%%%%%%_,_,");
    mvwprintw(_win, y + 1, x, "                   ~~%%%%%%%%%%%%%%%%%%-\"/./");
    mvwprintw(_win, y + 2, x, "                 ~~%%%%%%%%%%%%%%-'   /  `.");
    mvwprintw(_win, y + 3, x, "              ~~%%%%%%%%%%%%%%%%'  .     ,__;");
    mvwprintw(_win, y + 4, x, "            ~~%%%%%%%%%%%%%%%%'   :       \\O\\");
    mvwprintw(_win, y + 5, x, "          ~~%%%%%%%%%%%%%%%%'    :          `.");
    mvwprintw(_win, y + 6, x, "       ~~%%%%%%%%%%%%%%%%'       `. _,        '");
    mvwprintw(_win, y + 7, x, "    ~~%%%%%%%%%%%%%%%%'          .'`-._        `.");
    mvwprintw(_win, y + 8, x, " ~~%%%%%%%%%%%%%%%%%%'           :     `-.     (,;");
    mvwprintw(_win, y + 9, x, "~~%%%%%%%%%%%%%%%%'             :         `._\\_.'");
    mvwprintw(_win, y + 10, x, "~~%%%%%%%%%%%%%%'              ;");
    wrefresh(_win);
}

UserDisplay::UserDisplay(UserDisplay const &) {};
UserDisplay &
UserDisplay::operator=(UserDisplay const &) {return *this;};