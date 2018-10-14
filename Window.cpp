#include "Window.hpp"

Window::Window(void) {
    _readWin();
    _mod = true;
    _initNcurs();
    _timeDisplay = new TimeDisplay(_win[_windows[0]]);
    _infoDisplay = new InfoDisplay(_win[_windows[1]]);
    _cpuDisplay = new CPUUsageDisplay(_win[_windows[2]]);
    _physDisplay = new PhysMemoryDisplay(_win[_windows[3]]);
    _netDisplay = new NetDisplay(_win[_windows[4]]);
    _userDisplay = new UserDisplay(_win[_windows[5]]);
    _colors[0] = COLOR_BLUE;
    _colors[1] = COLOR_GREEN;
    _colors[2] = COLOR_RED;
    _colors[3] = COLOR_YELLOW;
    _colors[4] = COLOR_CYAN;
    _colors[5] = COLOR_MAGENTA;
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
Window::_readWin(void) {
    int i = -1;
    while (++i < 6)
        _windows[i] = 7;
    try{
        std::ifstream fin("Config");
        if (!fin.is_open())
            throw std::logic_error("Can't open file");
        std::stringstream buff;
        buff << fin.rdbuf();
        fin.close();
        std::string text = buff.str();
        if (text.length() != 7)
            throw std::logic_error("Invalid string in file");
        int i = -1;
        while (++i < 6) {
            if (text[i] - '0' > 5 || text[i] - '0' < 0)
                throw std::logic_error("Invalid string in file");
            int j = -1;
            while (++j < i)
                if (text[i] - '0' == _windows[j])
                    throw std::logic_error("Invalid string in file");
            _windows[i] = text[i] - '0';
        }
    }
    catch(std::exception & e) {
        int i = -1;
         while (++i < 6)
            _windows[i] = 5 - i;
    }
};

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
    start_color();
    
    _createBoxes();
}

void
Window::spin(void) {
    int c = getch();
    int x = 0;
    int y = 0;
    _createBoxes();
    while (c != 27 && c != 'q') {
        _iter();
        c = getch();
    }
    endwin();
}

void
Window::_iter(void) {
    try{
    _userDisplay->display();
    _timeDisplay->display();
    _infoDisplay->display();
    _netDisplay->display();
    _cpuDisplay->display();
    _physDisplay->display();
    refresh();
    }
    catch (std::exception & e) {
        endwin();
        std::cout << e.what() << std::endl;
        exit(-1);
    }
}