#include "NetModule.hpp"

NetModule::NetModule() {};
NetModule::~NetModule(void) {};

void
NetModule::compute() {
    FILE *buffer = popen("top", "r");
    char fromtop[300];
    int i = -1;
    while (++i < 10)
    {
        fgets(fromtop, 300, buffer);
        if (i == 8)
            _data.assign(fromtop);
    }
    _data.assign(_data.substr(0, _data.length() - 1));
}

NetModule::NetModule(NetModule const &) {};
NetModule &
NetModule::operator=(NetModule const &) {return *this;};
