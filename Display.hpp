#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <ncurses.h>

#include "IMonitorDisplay.hpp"
#include "Module.hpp"

class Display : public IMonitorDisplay {
public:
    Display() {};
    Display(WINDOW *win);
    virtual ~Display(void);
    virtual void display();
protected:
    WINDOW*     _win;

    
};

#endif