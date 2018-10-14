#include <iostream>
#include "Window.hpp"

int main(void) {
    
    Window win;
    win.spin();

//processor
//     buffer = popen("sysctl machdep.cpu.brand_string", "r");
//     char proc[100];
//     fgets(proc, 100, buffer);
//     std::cout << "processor" << proc;
//     pclose(buffer);

    return 0;
}
