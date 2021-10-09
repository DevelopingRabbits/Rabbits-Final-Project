#pragma once
#ifndef UI_H
#define UI_h
#include <iostream>
#include <string>

using namespace std;

class UI
{
private:
    const int MAX_STRING_LENGTH = 25;
    string playerName;
public:
    string stringInputValidation(string input);
    string getPlayerName();
    int integerInputValidation(int input);
    void clearBuffer();
};

#endif