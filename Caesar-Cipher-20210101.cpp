/*
Author: Gasser ahmed

Course: CSCI-136

Instructor:

Assignment: problem 1 "caesar cipher", Lab 23 / group B

This programme helps the user to cipher or decipher a message
by shifting letters with choosable number of shifts
*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string the_string()
{
    string name = "";
    getline(cin, name);
    return name;
}
int main()
{
    int shifts, option;
    string input_msg = "";
    bool x = true;
    while (x == true)
    {
        cout << "Hello user => Enter number of option you like to do \n 1-Cipher a essage \n 2-Decipher a message \n 3-Exit \n";
        cin >> option;
        if (option == 1)
        {
            cout << "please enter msg you want to cipher: \n";
            the_string();
            input_msg = the_string();
            cout << "enter the number of shifts you want to the right or left(positive or negative). \n";
            cin >> shifts;
            if (shifts > 26 || shifts < -26)
                shifts = shifts % 26;
            transform(input_msg.begin(), input_msg.end(), input_msg.begin(), ::toupper);
            cout << input_msg << endl;
            cout << "# ciphered msg is => ";
            for (int i = 0; i <= input_msg.length(); i++)
            {
                if (input_msg[i] != 32)
                {
                    input_msg[i] += shifts;
                    if (input_msg[i] > 90)
                        input_msg[i] -= 26;
                    if (input_msg[i] < 65)
                        input_msg[i] += 26;
                    cout << (char)input_msg[i];
                }
                else
                {
                    cout << " ";
                }
            }
        }
        if (option == 2)
        {
            cout << "please enter msg you want to Decipher: \n";
            the_string();
            input_msg = the_string();
            cout << "enter number of shifts in the ciphered message: \n";
            cin >> shifts;
            if (shifts > 26 || shifts < -26)
                shifts = shifts % 26;
            shifts *= -1;
            transform(input_msg.begin(), input_msg.end(), input_msg.begin(), ::toupper);
            cout << input_msg << endl;
            cout << "# deciphered msg is => ";
            for (int i = 0; i <= input_msg.length(); i++)
            {
                if (input_msg[i] != 32)
                {
                    input_msg[i] += shifts;
                    if (input_msg[i] > 90)
                        input_msg[i] -= 26;
                    if (input_msg[i] < 65)
                        input_msg[i] += 26;
                    cout << (char)input_msg[i];
                }
                else
                    cout << " ";
            }
        }
        if (option == 3)
        {
            x = false;
            cout << "(=> programme ended <=)";
            break;
        }
        cout << endl;
        cout << "______________________________________________________________________" << endl;
    }
}
