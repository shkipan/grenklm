#ifndef NETMODULE_HPP
#define NETMODULE_HPP

#include "Module.hpp"

class NetModule : public Module {
public:
    NetModule(void);
    virtual ~NetModule(void);
    virtual void compute();

private:
    NetModule(NetModule const &);
    NetModule & operator=(NetModule const &);
};

#endif