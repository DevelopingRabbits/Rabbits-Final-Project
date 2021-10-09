#include "UI.h"
#include <iostream>
using namespace std;

string UI::getPlayerName()
{
    cout << "Enter your name: ";
    cin >> playerName;
    return playerName;
}

string UI::stringInputValidation(string input)
{
    int stringSize;
    bool flag = false;

    while (input.length() >= MAX_STRING_LENGTH) //check that the length of the name is less than 25 characters
    {
        cout << "Your name should be less than 25 characters." << endl;

        input.clear();
        cout << "What is your name?\n";
        cin >> input;
    }


    while (flag == false)
    {
        stringSize = input.length();

        for (int i = 0; i <= stringSize; i++)//iterate through the string and check that there is only letters.
        {

            if (!isalpha(input[i]))
            {
                cout << "The name may only contain letters. Try again." << endl;
                cin.clear(); //reset the buffer

                cin.ignore(numeric_limits<streamsize>::max(), '\n');//empty the buffer
                cin >> input;
                break;
            }
            else if (i == stringSize - 1)//if a string is fully iterated through and only letters were found, set the flag to true in order to break out of the while loop.
            {
                flag = true;
                break;
            }

        }
    }
    clearBuffer();

    return input;//return the name that now only consists of letters

}

void UI::clearBuffer()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
