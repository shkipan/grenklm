#include "InfoModule.hpp"

InfoModule::InfoModule() {};
InfoModule::~InfoModule(void) {};

void
InfoModule::compute() {
    FILE *buffer = popen("system_profiler SPSoftwareDataType", "r");
    if (!buffer) throw std::runtime_error("popen() failed!");
    char syst[100];
    std::string temp;
    int i = -1;
    while (++i < 13)
    {
        fgets(syst, 100, buffer);
        if (i > 3)
        {
            temp.assign(syst);
            _data.append(temp);
        }
    }
    pclose(buffer);
}

InfoModule::InfoModule(InfoModule const &) {};
InfoModule &
InfoModule::operator=(InfoModule const &) {return *this;};
