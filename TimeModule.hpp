#ifndef TIMEMODULE_HPP
#define TIMEMODULE_HPP

#include "Module.hpp"
#include <time.h>

class TimeModule : public Module {
public:
    TimeModule(void);
    virtual ~TimeModule(void);
    virtual void compute();

private:
    TimeModule(TimeModule const &);
    TimeModule & operator=(TimeModule const &);

};

#endif