// src/presentation/ConsoleUI.h
#ifndef CONSOLE_UI_H
#define CONSOLE_UI_H

#include "UserInterface.h"


class ConsoleUI : public UserInterface {
public:
    void displayMessage(const string& message) override {
        cout << message << endl;
    }

    void getUserInput(string& input) override {
        getline(cin, input);
    }
};

#endif // CONSOLE_UI_H
