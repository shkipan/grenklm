#ifndef TIMEDISPLAY_HPP
#define TIMEDISPLAY_HPP

#include "Display.hpp"
#include "TimeModule.hpp"

class TimeDisplay : public Display {
public:
    TimeDisplay(WINDOW *win);
    virtual ~TimeDisplay(void);
    virtual void display();

private:
    TimeDisplay(TimeDisplay const &);
    TimeDisplay & operator=(TimeDisplay const &);
    TimeModule*     _module;

};

#endif