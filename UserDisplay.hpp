#ifndef UserDISPLAY_HPP
#define UserDISPLAY_HPP

#include "Display.hpp"
#include "UserModule.hpp"

class UserDisplay : public Display {
public:
    UserDisplay(WINDOW *win);
    virtual ~UserDisplay(void);
    virtual void display();
private:
    UserDisplay(UserDisplay const &);
    UserDisplay & operator=(UserDisplay const &);
    UserModule* _module;
};

#endif