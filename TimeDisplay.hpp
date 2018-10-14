#ifndef TIMEDISPLAY_HPP
#define TIMEDISPLAY_HPP

#include "Display.hpp"
#include "TimeModule.hpp"

class TimeDisplay : public Display {
public:
    TimeDisplay(WINDOW *win);
    virtual ~TimeDisplay(void);
    virtual void display();

    void disp_time(int x, int y, std::string s);
    void disp_date(int x, int y, std::string s);
    void disp0(int x, int y);
    void disp1(int x, int y);
    void disp2(int x, int y);
    void disp3(int x, int y);
    void disp4(int x, int y);
    void disp5(int x, int y);
    void disp6(int x, int y);
    void disp7(int x, int y);
    void disp8(int x, int y);
    void disp9(int x, int y);
    void dispc(int x, int y);
    void dispm(int x, int y);

private:
    TimeDisplay(TimeDisplay const &);
    TimeDisplay & operator=(TimeDisplay const &);
    TimeModule*     _module;

};

#endif