#include "Window.hpp"

Window::Window(void) {    
    _mod = true;
    _initNcurs();
    _infoDisplay = new InfoDisplay(_win[1]);
    _netDisplay = new NetDisplay(_win[4]);
    _timeDisplay = new TimeDisplay(_win[0]);
    _userDisplay = new UserDisplay(_win[5]);
    _cpuDisplay = new CPUUsageDisplay(_win[2]);
    _physDisplay = new PhysMemoryDisplay(_win[3]);
    _iter();
};
Window::~Window(void) {
    delete _timeDisplay;
    delete _userDisplay;
    delete _infoDisplay;
    delete _netDisplay;
    delete _cpuDisplay;
};
Window::Window(Window const &) {};
Window & 
Window::operator=(Window const &) {return *this;};

void
Window::_createBoxes(void) {
    int x = 0;
    int y = 0;
    getmaxyx(stdscr, y, x);
    int dx = x / 3;
    int dy = y / 2;
    for (int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            _win[i * 3 + j] = newwin(dy, dx, i * dy, j * dx);
            box(_win[i * 3 + j], 0, 0);
            wrefresh(_win[i * 3 + j]);
        }
    }
            refresh();
}

void
Window::_initNcurs(void) {

    initscr();
    keypad(stdscr, true);
    cbreak();
    timeout(0);
    curs_set(FALSE);
    noecho();
    int c = -1;
    while (++c < 6)
        _win[c] = NULL;
    _createBoxes();
}

void
Window::spin(void) {
    int c = getch();
    _createBoxes();
    while (c != 27) {
        _iter();
        c = getch();
    }
    endwin();
}

void
Window::_iter(void) {
    _userDisplay->display();
    _timeDisplay->display();
    _infoDisplay->display();
    _netDisplay->display();
    _cpuDisplay->display();
    _physDisplay->display();
    refresh();
}