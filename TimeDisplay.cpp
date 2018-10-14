#include "TimeDisplay.hpp"

TimeDisplay::TimeDisplay(WINDOW *win) : Display(win) {_module = new TimeModule;};
TimeDisplay::~TimeDisplay(void) {delete _module;};

void
TimeDisplay::display() {
    _module->compute();
    box(_win, 0, 0);
    mvwprintw(_win, 2, 2, "TimeDisplay");
    mvwprintw(_win, 3, 2, _module->getData().substr(0,  _module->getData().find(" ")).c_str());
    mvwprintw(_win, 4, 2, _module->getData().substr(_module->getData().find(" ") + 1, _module->getData().size() - _module->getData().find(" ") - 1).c_str());
    wrefresh(_win);
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