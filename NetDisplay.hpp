#ifndef NETDISPLAY_HPP
#define NETDISPLAY_HPP

#include "Display.hpp"
#include "NetModule.hpp"

class NetDisplay : public Display {
public:
    NetDisplay(WINDOW *win);
    virtual ~NetDisplay(void);
    virtual void display();

private:
    NetDisplay(NetDisplay const &);
    NetDisplay & operator=(NetDisplay const &);
    NetModule*     _module;

};

#endif