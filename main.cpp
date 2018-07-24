#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include "helperFunctions.h"

using namespace std;
//----------------------------------------------------------------------
// File name: main.cpp
// Project name: Snippet Generator
//----------------------------------------------------------------------
// Creator's name and email: Roger Chavez roger.chavez.03@gmail.com
// Course-section: CS 1B
// Creation Date: 07-19-2018
// Date of Last Modification: 07-20-2018
//----------------------------------------------------------------------
// Purpose: Takes code and wraps it line by line in double quotes and if the
//          string already contains double quotes it will find where they are
//          insert a backslash behind it \.
//----------------------------------------------------------------------
// Algorithm:
//     Step 1: open file containing text you want to convert to a snippet and extract it
//     Step 2: get the desired name, prefix and description for the snippet
//     Step 3: go through each string and locate double quotes, insert backslashes if it finds any
//     Step 4: wrap each line in double quotes and seperate each line by a comma, except for the last line
//     Step 5: Print out the snippet to the console
// --------------------------------------------------------------
// -                     DATA DICTIONARY
// - CONSTANTS
// - NAME               DATA TYPE           VALUE
// - ------------------ ------------------  ------------------
// -
// -
// - STRUCTS
// - NAME                              DATA TYPE                  VALUE
// - ------------------ ------------------ ------------------
// -
// - NAME                              DATA TYPE                  VALUE
// - ------------------ ------------------ ------------------
// -
// -
// - VARIABLES
// - NAME               DATA TYPE          VALUE
// - ------------------ ------------------ ------------------
// -
// --------------------------------------------------------------
int main()
{
    string stringDB[100];
    string name;
    string prefix;
    string description;
    int index = 0;
    getFileData(stringDB, index, "futureSnippet.txt");
    cout << setw(130) << "__________________________________________________________________________________________________________________________________" << endl;
    cout << setw(130) << "|                                                                                                                                |" << endl;
    cout << setw(52) << "|                                                   " << setw(26) << "       Snippet Gen         " << setw(52) << "                                                   |" << endl;
    cout << setw(130) << "|                                                                                                                                |" << endl;
    cout << setw(130) << "|________________________________________________________________________________________________________________________________|" << endl;
    cout << "What would you like to call your snippet? : ";
    getline(cin, name);
    sysClear();
    cout << "Please type the prefix youd like to use call your snippet?: ";
    getline(cin, prefix);
    sysClear();
    cout << "Please type a brief description for your snippet: ";
    getline(cin, description);
    sysClear();
    cout << endl;
    cout << endl;
    sysClear();
    cout << setw(52) << "                                                    " << setw(26) << "       Your Snippet         " << setw(52) << "                                                    " << endl;
    cout << endl;
    cout << "\"" << name << "\":{" << endl;
    cout << "\"prefix\": \"" << prefix << "\"," << endl;
    cout << "\"body\": [" << endl;

    for (int i = 0; i < index; i++)
    {

        vector<size_t> positions;

        size_t pos = stringDB[i].find("\"", 0);
        while (pos != string::npos)
        {
            positions.push_back(pos);
            pos = stringDB[i].find("\"", pos + 1);
        }
        
        pos = stringDB[i].find("\\n", 0);
        while (pos != string::npos)
        {
            positions.push_back(pos);
            pos = stringDB[i].find("\\n", pos + 1);
        }

        for (size_t j = 0; j < positions.size(); j++)
        {
            stringDB[i].insert(static_cast<int>(positions[j] + j), "\\");
        }

        cout << "\"" << stringDB[i] << "\"";
        if ((i + 1) < index)
        {
            cout << ",";
        }
        cout << endl;
    }
    cout << "]," << endl;
    cout << "\"Test\": \"" << description << "\"" << endl;
    cout << "}," << endl;
    return 0;
}
