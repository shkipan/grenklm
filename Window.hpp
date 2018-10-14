#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <ncurses.h>
#include "InfoDisplay.hpp"
#include "NetDisplay.hpp"
#include "TimeDisplay.hpp"
#include "UserDisplay.hpp"
#include "CPUUsageDisplay.hpp"
#include "PhysMemoryDisplay.hpp"

#define TIME_VAL(t1, t2) (((t2).tv_sec * 1000000 + (t2).tv_usec) - ((t1).tv_sec * 1000000 + (t1).tv_usec))


class Window {
public:
    Window(void);
    Window(Window const &);
    ~Window(void);
    Window & operator=(Window const &);
    void    spin(void);

private:
    void    _iter(void);
    void    _initNcurs(void);
    void    _createBoxes(void);
    bool    _mod;
    WINDOW  *_win[6];
    Display* _infoDisplay;
    Display* _netDisplay;
    Display* _timeDisplay;
    UserDisplay* _userDisplay;
    CPUUsageDisplay* _cpuDisplay;
    PhysMemoryDisplay* _physDisplay;

};

#endif