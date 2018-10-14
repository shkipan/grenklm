#ifndef INFODISPLAY_HPP
#define INFODISPLAY_HPP

#include "Display.hpp"
#include "InfoModule.hpp"

class InfoDisplay : public Display {
public:
    InfoDisplay(WINDOW *win);
    virtual ~InfoDisplay(void);
    virtual void display();

private:
    InfoDisplay(InfoDisplay const &);
    InfoDisplay & operator=(InfoDisplay const &);
    InfoModule* _module;

};

#endif