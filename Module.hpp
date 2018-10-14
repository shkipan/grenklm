#ifndef MODULE_HPP
#define MODULE_HPP

#include <iostream>
#include "IMonitorModule.hpp"

class Module : public IMonitorModule {
public:
    Module() {};
    virtual ~Module(void);
    std::string &  getData(void);
    void           compute(void);

protected:
    std::string _data;

};

#endif