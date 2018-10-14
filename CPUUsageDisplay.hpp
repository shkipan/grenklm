#ifndef CPUUSAGEDISPLAY_HPP
#define CPUUSAGEDISPLAY_HPP

#include "Display.hpp"
#include "CPUUsageModule.hpp"

class CPUUsageDisplay : public Display {
public:
    CPUUsageDisplay(WINDOW *win);
    virtual ~CPUUsageDisplay(void);
    virtual void display();

private:
    CPUUsageDisplay(CPUUsageDisplay const &);
    CPUUsageDisplay & operator=(CPUUsageDisplay const &);
    CPUUsageModule*     _module;

};

#endif