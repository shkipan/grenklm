#include "TimeDisplay.hpp"

TimeDisplay::TimeDisplay(WINDOW *win) : Display(win) {_module = new TimeModule;};
TimeDisplay::~TimeDisplay(void) {delete _module;};

void
TimeDisplay::display() {
    _module->compute();
    int x, y;
    getmaxyx(_win, y, x);
    mvwprintw(_win, 2, (x - 12) / 2, "Time Display");
    mvwprintw(_win, y / 2 - 3, (x - 8) / 2, _module->getData().substr(0,  _module->getData().find(" ")).c_str());
    mvwprintw(_win, y / 2 - 2, (x - 10) / 2, _module->getData().substr(_module->getData().find(" ") + 1, _module->getData().size() - _module->getData().find(" ") - 1).c_str());
    wrefresh(_win);
    _module->getData().clear();
}

TimeDisplay::TimeDisplay(TimeDisplay const &) {};
TimeDisplay &
TimeDisplay::operator=(TimeDisplay const &) {return *this;};


//       :::::::    :::    ::::::::   ::::::::      :::    ::::::::::  ::::::::  :::::::::::  ::::::::   ::::::::     
//     :+:   :+: :+:+:   :+:    :+: :+:    :+:    :+:     :+:    :+: :+:    :+: :+:     :+: :+:    :+: :+:    :+: :+: 
//    +:+   +:+   +:+         +:+         +:+   +:+ +:+  +:+        +:+               +:+  +:+    +:+ +:+    +:+      
//   +#+   +:+   +#+       +#+        +#++:   +#+  +:+  +#++:++#+  +#++:++#+        +#+    +#++:++#   +#++:++#+       
//  +#+   +#+   +#+     +#+             +#+ +#+#+#+#+#+       +#+ +#+    +#+      +#+    +#+    +#+        +#+        
// #+#   #+#   #+#    #+#       #+#    #+#       #+#  #+#    #+# #+#    #+#     #+#     #+#    #+# #+#    #+# #+#     
// #######  ####### ##########  ########        ###   ########   ########      ###      ########   ########           