#ifndef USERMODULE_HPP
#define USERMODULE_HPP

#include "Module.hpp"
#include <unistd.h>

class UserModule : public Module {
public:
    UserModule(void);
    virtual ~UserModule(void);
    virtual void compute();

private:
    UserModule(UserModule const &);
    UserModule & operator=(UserModule const &);
};

#endif