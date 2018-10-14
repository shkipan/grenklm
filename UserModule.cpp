#include "UserModule.hpp"

UserModule::UserModule() {};
UserModule::~UserModule(void) {};

void
UserModule::compute() {
    char *name = getlogin();
    _data.assign(name);
}

UserModule::UserModule(UserModule const &) {};
UserModule &
UserModule::operator=(UserModule const &) {return *this;};
