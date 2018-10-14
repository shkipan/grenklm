#ifndef UserDISPLAY_HPP
#define UserDISPLAY_HPP

#include "Display.hpp"
#include "UserModule.hpp"

class UserDisplay : public Display {
public:
    UserDisplay(WINDOW *win);
    virtual ~UserDisplay(void);
    virtual void display();
    void    disp0(int x, int y);
    void    disp1(int x, int y);
    void    disp2(int x, int y);
    void    disp3(int x, int y);
    void    disp4(int x, int y);
    void    disp5(int x, int y);
    void    disp6(int x, int y);
    void    disp7(int x, int y);
    void    disp8(int x, int y);
    void    disp9(int x, int y);
    void    dispm(int x, int y);
    void    dispc(int x, int y);

    
private:
    UserDisplay(UserDisplay const &);
    UserDisplay & operator=(UserDisplay const &);
    UserModule* _module;
};

#endif