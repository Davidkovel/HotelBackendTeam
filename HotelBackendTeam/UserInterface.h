#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include "library.h"

class UserInterface {
public:
    virtual void displayMessage(const string& message) = 0;
    virtual void getUserInput(string& input) = 0;
    virtual ~UserInterface() {}
};

#endif // USER_INTERFACE_H
