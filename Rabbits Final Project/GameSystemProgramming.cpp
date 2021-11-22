#include "GameSystemsProgramming.h"
#include <iostream>
using namespace std;

string GameSystemsProgramming::getPlayerName()
{
    cout << "Enter your name: ";
    cin >> playerName;
    return playerName;
}

string GameSystemsProgramming::stringInputValidation(string input)
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

    /*The following block of code ensures that each character in the string is a letter.
    * The string is measured for size and then each element of the string is checked (the for loop)
    * If the element is not a letter, prompt the user to input a new string.
    * If the string has been fully iterated through, break the while loop by setting the flag to true.
    */
    while (flag == false)
    {
        stringSize = input.length();

        for (int i = 0; i <= stringSize; i++)//iterate through the string and check that there is only letters.
        {

            if (!isalpha(input[i]))
            {
                cout << "The input may only contain letters. Try again." << endl;
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

int GameSystemsProgramming::integerInputValidation(int input)
{
    /*
       Test to see if an integer value is infact valid.
       If it is not valid clear the input and prompt the user for a new input.
    */
    bool valid = false;
    while (!valid)
    {

        if (cin.good())
        {
            
            //the input is a valid integer, break out of the loop.
            valid = true;
        }
        else
        {
            cin.clear(); //reset the buffer

            cin.ignore(numeric_limits<streamsize>::max(), '\n');//empty the buffer
            cout << "Invalid Input..." << endl;

            cout << " Enter your choice: "; // Display Options to user
            cin >> input; // Collect User Input and compare it to the switch statement.
        }
    }



    return input;//return the name that now only consists of letters
}

int GameSystemsProgramming::stringToIntegerInputValidation(string input)
{   
    int returnInput;
    int stringSize = input.size();
    
    bool valid = false;
    while (!valid)
    {

        for (int i = 0; i < stringSize; i++)
        {
            
            if (!isdigit(input[i]))
            {
                cin.clear(); //reset the buffer

                cin.ignore(numeric_limits<streamsize>::max(), '\n');//empty the buffer
                cout << "Invalid Input..." << endl;

                cout << " Enter your choice: "; // Display Options to user
                cin >> input; // Collect User Input and compare it to the switch statement.
                stringSize = input.size();
                i = -1;
            }
            else if(i == stringSize-1)
            {

               returnInput = stoi(input);
               valid = true;
            }
            
        }
       
    }



    return returnInput;//return the name that now only consists of letters
}
void GameSystemsProgramming::clearBuffer()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void GameSystemsProgramming::loseMessage()
{
    cout << "GAME OVER";
}

void GameSystemsProgramming::yourChoiceMessage()
{
  cout << "Your Choice: ";
}

#include <Windows.h>
void GameSystemsProgramming::delay()
{
  for (int i = 0; i < 1; i++)
  {
    cout << i;
    Sleep(500);
    system("cls");
  }
}