#include <iostream>
#include <iomanip>
#include <ctime>
#include <fstream>
#include "helperFunctions.h"

using namespace std;

void checkState(bool &error)
{
	if (cin.fail()) // ERROR CHECKING - If true it resets the buffer and set's choice to a failed number so a message is displayed for the error
	{
		cin.clear();
		cin.ignore(1000, '\n');
		error = true;
	}
}

string getDate()
{

	string nowDate;
	time_t t = time(0);
	tm *now = localtime(&t);
	nowDate = to_string(now->tm_mon + 1) + '-' + to_string(now->tm_mday) + '-' + to_string(now->tm_year + 1900);
	return nowDate;
}

// ------------------
// 	selectionSort
// ------------------
// How it gets called - Takes in an array, a variable with the value of how many elements are in the array
// What changes because of the function - reorders the array from smallest to biggest
// -----------------
void selectionSort(int a[], int length)
{

	/* a[0] to a[n-1] is the array to sort */
	long i, j;
	// change manually,ask to figure out how to make it dynamic
	long n = length;

	/* advance the position through the entire array */
	/*   (could do j < n-1 because single element is also min element) */
	for (j = 0; j < n - 1; j++)
	{
		/* find the min element in the unsorted a[j .. n-1] */

		/* assume the min is the first element */
		long iMin = j;
		/* test against elements after j to find the smallest */
		for (i = j + 1; i < n; i++)
		{
			/* if this element is less, then it is the new minimum */
			if (a[i] < a[iMin])
			{
				/* found new minimum; remember its index */
				iMin = i;
			}
		}

		if (iMin != j)
		{
			long temp;
			temp = a[j];
			a[j] = a[iMin];
			a[iMin] = temp;
		}
	}
}

void responseCheck(char yesOrNo, bool &response, bool &badResponse)
{
	if (yesOrNo == 'y' || yesOrNo == 'Y')
		response = true;

	else if (yesOrNo == 'n' || yesOrNo == 'N')
		response = false;
	else
		badResponse = true;
}

// ------------------
// 	getFileData
// ------------------
// How it gets called - Need's an array, an int variable that represents the index, the size of the array, and the location of the file containing the data
// What changes because of the function - This will populate the array and will set how many elements were put into the array into index.
// -----------------
void getFileData(string data[], int &index, string file)
{
	ifstream inFile;

	index = 0;
	inFile.open(file.c_str());

	if (inFile.fail())
	{
		cout << "There was an error opening your file at location " << file << endl;
		exit(1);
	}

	do
	{
		getline(inFile, data[index]);
		index++;
	} while (!inFile.eof());

	inFile.close();
}
// void getFileData(int data[], int &index, int size, string file)
// {
// 	ifstream inFile;

// 	index = 0;
// 	inFile.open(file.c_str());

// 	if (inFile.fail())
// 	{
// 		cout << "There was an error opening your file at location " << file << endl;
// 		exit(1);
// 	}

// 	do
// 	{
// 		inFile >>
// 		index++;
// 	} while (!inFile.eof() && index < size);

// 	inFile.close();
// }

// ------------------
// 	makeFileData
// ------------------
// How it gets called - Takes in an array, a variable with the value of how many elements are in the array and the name of the file being written
// What changes because of the function - writes an array out to a file.
// -----------------
void makeFileData(int data[], int &index, string s)
{
	ofstream outFile;
	outFile.open(s.c_str());
	if (outFile.fail())
	{
		cout << "There was an error opening your file at location " << s << endl;
		exit(1);
	}

	for (int i = 0; i < index; i++)
	{
		outFile << data[i] << " ";
		if ((i + 1) % 10 == 0)
		{
			outFile << '\n';
		}
	}

	outFile.close();
}

#ifdef _WIN32
#include <windows.h>

void sysPause()
{
	system("pause");
}

void sysClear()
{
	system("cls");
}
void clearLine()
{
	printf("\33[2K\r");
	s
}
#endif

#ifdef __APPLE__

void sysPause()
{
	system("read -n 1 -s -p \"Press any key to continue...\"");
}

void sysClear()
{
	cout << "\033[2J\033[1;1H";
}
void clearLine()
{
	printf("\33[2K\r");
}
#endif
