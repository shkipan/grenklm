#include "NetModule.hpp"

NetModule::NetModule() {};
NetModule::~NetModule(void) {};

void
NetModule::compute() {
    FILE *buffer = popen("top", "r");
    char ftop[300];
    int i = -1;
    while (++i < 10)
    {
        fgets(ftop, 300, buffer);
        if (i == 8)
        {
            _data.assign(ftop);
            _data = _data.substr(_data.find("ts:") + 3, _data.length() - _data.find("ts:") - 3);
        }
    }
    _data.assign(_data.substr(0, _data.length() - 1));
}

NetModule::NetModule(NetModule const &) {};
NetModule &
NetModule::operator=(NetModule const &) {return *this;};
