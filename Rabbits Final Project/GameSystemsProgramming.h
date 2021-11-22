#pragma once
#ifndef GameSystemsProgramming_H
#define GameSystemsProgramming_h
#include <iostream>
#include <string>


using namespace std;

class GameSystemsProgramming
{
private:
    const int MAX_STRING_LENGTH = 25;
    string playerName;
public:
    string stringInputValidation(string input);
    string getPlayerName();
    int integerInputValidation(int input);
    int stringToIntegerInputValidation(string input);
    void clearBuffer();

    void delay();
    void yourChoiceMessage();

    void loseMessage();
};
// This is a test!!!!!!!
#endif