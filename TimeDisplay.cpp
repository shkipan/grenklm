#include "TimeDisplay.hpp"

TimeDisplay::TimeDisplay(WINDOW *win) : Display(win) {_module = new TimeModule;};
TimeDisplay::~TimeDisplay(void) {delete _module;};

void
TimeDisplay::display() {
    _module->compute();
    int x, y;
    getmaxyx(_win, y, x);
    init_pair(23, COLOR_GREEN, COLOR_BLACK);
    wattron(_win, COLOR_PAIR(23));
    mvwprintw(_win, 2, (x - 16) / 2, "Date/Time Display");
    disp_time(5, 14, _module->getData().substr(0,  _module->getData().find(" ")));
    disp_date(10, 4, _module->getData().substr(_module->getData().find(" ") + 1, _module->getData().size() - _module->getData().find(" ") - 1));
    box(_win, 0, 0);
    wattroff(_win, COLOR_PAIR(23));
    wrefresh(_win);
    _module->getData().clear();
}

TimeDisplay::TimeDisplay(TimeDisplay const &) {};
TimeDisplay &
TimeDisplay::operator=(TimeDisplay const &) {return *this;};

void
TimeDisplay::disp_time(int x, int y, std::string s) {
    static void (TimeDisplay::*ft[12])(int x, int y) =
	{&TimeDisplay::disp0, &TimeDisplay::disp1, &TimeDisplay::disp2, 
    &TimeDisplay::disp3, &TimeDisplay::disp4, &TimeDisplay::disp5, 
    &TimeDisplay::disp6, &TimeDisplay::disp7, &TimeDisplay::disp8, 
    &TimeDisplay::disp9, &TimeDisplay::dispc, &TimeDisplay::dispm};

    int n = -1;
    int _x = x;
    int _y = y;
    while (++n < 8)
    {
        mvwprintw(_win, _x, _y, "    ");
        mvwprintw(_win, _x + 1, _y, "    ");
        mvwprintw(_win, _x + 2, _y, "    ");
        mvwprintw(_win, _x + 3, _y, "    ");
        if (s[n] == ':')
            (this->*ft[10])(_x, _y);
        else
            (this->*ft[s[n] - '0'])(_x, _y);
       _y += 5;
    }
}

void
TimeDisplay::disp_date(int x, int y, std::string s) {
    static void (TimeDisplay::*ft[12])(int x, int y) =
	{&TimeDisplay::disp0, &TimeDisplay::disp1, &TimeDisplay::disp2, 
    &TimeDisplay::disp3, &TimeDisplay::disp4, &TimeDisplay::disp5, 
    &TimeDisplay::disp6, &TimeDisplay::disp7, &TimeDisplay::disp8, 
    &TimeDisplay::disp9, &TimeDisplay::dispc, &TimeDisplay::dispm};

    int n = -1;
    int _x = x;
    int _y = y;
    while (++n < 10)
    {
        if (s[n] == ':')
            (this->*ft[10])(_x, _y);
        else if (s[n] == '-')
            (this->*ft[11])(_x, _y);
        else
            (this->*ft[s[n] - '0'])(_x, _y);
       _y += 6;
    }
}
void
TimeDisplay::disp0(int x, int y) {
    mvwprintw(_win, x, y, ",--.");
    mvwprintw(_win, x + 1, y, "|  |");
    mvwprintw(_win, x + 2, y, "|  |");
    mvwprintw(_win, x + 3, y, "`--'");
}

void
TimeDisplay::disp1(int x, int y) {
    mvwprintw(_win, x, y, "  '|");
    mvwprintw(_win, x + 1, y, "   |");
    mvwprintw(_win, x + 2, y, "   |");
    mvwprintw(_win, x + 3, y, "   |");
}

void
TimeDisplay::disp2(int x, int y) {
    mvwprintw(_win, x, y, ",--.");
    mvwprintw(_win, x + 1, y, ",--'");
    mvwprintw(_win, x + 2, y, "|   ");
    mvwprintw(_win, x + 3, y, "`--'");
}

void
TimeDisplay::disp3(int x, int y) {
    mvwprintw(_win, x, y, ",--.");
    mvwprintw(_win, x + 1, y, "  -|");
    mvwprintw(_win, x + 2, y, "   |");
    mvwprintw(_win, x + 3, y, "`--'");
}

void
TimeDisplay::disp4(int x, int y) {
    mvwprintw(_win, x, y, "|  |");
    mvwprintw(_win, x + 1, y, "`--|");
    mvwprintw(_win, x + 2, y, "   |");
    mvwprintw(_win, x + 3, y, "   ` ");
}

void
TimeDisplay::disp5(int x, int y) {
    mvwprintw(_win, x, y, "---.");
    mvwprintw(_win, x + 1, y, "`--.");
    mvwprintw(_win, x + 2, y, "   |");
    mvwprintw(_win, x + 3, y, "`--'");
}

void
TimeDisplay::disp6(int x, int y) {
    mvwprintw(_win, x, y, ",--.");
    mvwprintw(_win, x + 1, y, "|--.");
    mvwprintw(_win, x + 2, y, "|  |");
    mvwprintw(_win, x + 3, y, "`--'");
}

//   ---.    ,--.    ,--.                
//      /    ,--.    `__|        o       
//     |     |  |       |             ---
//     |     `--'       '        o       

void
TimeDisplay::disp7(int x, int y) {
    mvwprintw(_win, x, y, "---.");
    mvwprintw(_win, x + 1, y, "   /");
    mvwprintw(_win, x + 2, y, "  | ");
    mvwprintw(_win, x + 3, y, "  | ");
}

void
TimeDisplay::disp8(int x, int y) {
    mvwprintw(_win, x, y, ",--.");
    mvwprintw(_win, x + 1, y, ",--.");
    mvwprintw(_win, x + 2, y, "|  |");
    mvwprintw(_win, x + 3, y, "`--'");
}
void
TimeDisplay::disp9(int x, int y) {
    mvwprintw(_win, x, y, ",--.");
    mvwprintw(_win, x + 1, y, "`__|");
    mvwprintw(_win, x + 2, y, "   |");
    mvwprintw(_win, x + 3, y, "   '");
}
void
TimeDisplay::dispc(int x, int y) {
    mvwprintw(_win, x, y, "    ");
    mvwprintw(_win, x + 1, y, "  o ");
    mvwprintw(_win, x + 2, y, "    ");
    mvwprintw(_win, x + 3, y, "  o ");
}
void
TimeDisplay::dispm(int x, int y) {
    mvwprintw(_win, x, y, "    ");
    mvwprintw(_win, x + 1, y, "    ");
    mvwprintw(_win, x + 2, y, " ---");
    mvwprintw(_win, x + 3, y, "    ");
}