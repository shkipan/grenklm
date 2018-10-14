#ifndef INFOMODULE_HPP
#define INFOMODULE_HPP

#include "Module.hpp"

class InfoModule : public Module {
public:
    InfoModule(void);
    virtual ~InfoModule(void);
    virtual void compute();

private:
    InfoModule(InfoModule const &);
    InfoModule & operator=(InfoModule const &);
};

#endif