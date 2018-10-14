#ifndef IMONITORDISPLAY_HPP
#define IMONITORDISPLAY_HPP

class IMonitorDisplay {
public:
    virtual ~IMonitorDisplay(void) {};
    virtual void display() = 0;
};

#endif