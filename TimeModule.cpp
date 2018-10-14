#include "TimeModule.hpp"

TimeModule::TimeModule() {};
TimeModule::~TimeModule(void) {};

void
TimeModule::compute() {
    time_t     now = std::time(0);
    char       buf[80];

    strftime(buf, sizeof(buf), "%X %d-%m-%Y", localtime(&now));
    _data.clear();
    _data.assign(buf);
}

TimeModule::TimeModule(TimeModule const &) {};
TimeModule &
TimeModule::operator=(TimeModule const &) {return *this;};
