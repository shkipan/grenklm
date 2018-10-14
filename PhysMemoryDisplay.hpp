#ifndef PHYSMEMDISPLAY_HPP
#define PHYSMEMDISPLAY_HPP

#include "Display.hpp"
#include "PhysMemoryModule.hpp"

class PhysMemoryDisplay : public Display {
public:
    PhysMemoryDisplay(WINDOW *win);
    virtual ~PhysMemoryDisplay(void);
    virtual void display();

private:
    PhysMemoryDisplay(PhysMemoryDisplay const &);
    PhysMemoryDisplay & operator=(PhysMemoryDisplay const &);
    PhysMemoryModule*     _module;

};

#endif