#ifndef HELPERFUNCTIONS_H_
#define HELPERFUNCTIONS_H_

#include <string>
// #include "functions.h"
using namespace std;

// temp description need an int variable the represents the user choice, and bool variable that represents whether or not there was an error
void checkState(int &choice,
				bool &error);
void checkState(char &choice,
				bool &error);
void checkState(bool &error);
void getFileData(string[], int &, string);
string getDate();
string getTime();
// void linSearch(cashier[], int &, int, int &, bool &);
void responseCheck(char, bool &, bool &);
// void selectionSort(bookData[], int, int);

void sysClear();
void sysPause();
void clearLine();

#endif /* HELPERFUNCTIONS_H_ */
