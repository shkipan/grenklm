#include "Window.hpp"

Window::Window(void) {    
    _mod = true;
    _initNcurs();
    gettimeofday(&_startTime, NULL);
    //_infoDisplay = new InfoDisplay(_win[1]);
    _netDisplay = new NetDisplay(_win[2]);
    _timeDisplay = new TimeDisplay(_win[0]);
    // _userDisplay = new UserDisplay;
    _iter();
};
Window::~Window(void) {
    delete _timeDisplay;
    // delete _userDisplay;
    //delete _infoDisplay;
     delete _netDisplay;
};
Window::Window(Window const &) {};
Window & 
Window::operator=(Window const &) {return *this;};

void
Window::_createBoxes(void) {
    int x = 0;
    int y = 0;
    clear();
    getmaxyx(stdscr, y, x);
    int dx = x / 3;
    int dy = y / 2;
    int i = -1;
    int j = -1;
    while (++i < 2)
    {
        j = -1;
        while (++j < 3)
        {
            _win[i * 3 + j] = newwin(dy, dx, i * dy, j * dx);
            box(_win[i * 3 + j], 0, 0);
            wrefresh(_win[i * 3 + j]);
            refresh();
        }
    }
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
    while (c != 27) {
        c = getch();
        gettimeofday(&_currTime, NULL);
        if (TIME_VAL(_startTime, _currTime) >= 1000000)
            _iter();
    }
    endwin();
}

void
Window::_iter(void) {
    _createBoxes();
    // _userDisplay->display(_win[0], 1, 1);
    _timeDisplay->display();
    //_infoDisplay->display();
     _netDisplay->display();
    refresh();
    _startTime = _currTime;
}