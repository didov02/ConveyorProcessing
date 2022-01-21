/**
*
* Solution to course project # 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Dian Vasilev
* @idnumber fn6MI0600107
* @compiler VC
* @github https://github.com/didov02/ConveyorProcessing
* 
*/



#include <iostream>
#include<string>
#include<cmath>
#include<fstream>
#include<sstream>
#include "seenumbersandfunctions.h"
#include "changeonenumber.h"
#include "changeonefunction.h"
#include "getresult.h"
#include "getresultwithcarrymode.h"
#include "matrix.h"
#include "plaintext.h"
#include "jsonformat.h"

using namespace std;

void ChooseFromMenu()
{
	cout << "Menu:" << endl;
	cout << "1. See your numbers" << endl;
	cout << "2. Change one number" << endl;
	cout << "3. See your functions" << endl;
	cout << "4. Change one function" << endl;
	cout << "5. Create matrix and bring out the result" << endl;
	cout << "6. Save in plain text" << endl;
	cout << "7. Save in JSON format" << endl;
	cout << "8. Exit" << endl << endl;
}

void Options(int option)
{
	if (option == 1)//option one
	{
		SeeYourNumbers();
	}
	else if (option == 2)//option two
	{
		int line, newNumber;

		cout << "On witch line you want to change the number: ";
		cin >> line;//on which line you want to change the number

		cout << "New number: ";
		cin >> newNumber;//with which number do you want to change it

		ChangeOneNumber(line, newNumber);

		cout << endl;
	}
	else if (option == 3)//option three
	{
		SeeYourFunctions();
	}
	else if (option == 4)//option four
	{
		int line;
		string newFunction;

		cout << "On witch line you want to change the function: ";
		cin >> line;//on which line you want to change the function

		cout << "New function: ";
		cin >> newFunction;//with witch function do you want to change it

		ChangeOneFunction(line, newFunction);

		cout << endl;
	}
	else if (option == 5)//option five
	{
		Matrix();
	}
	else if (option == 6)//option six
	{
		string answer;
		cout << "Do you want to use carry mode?" << endl;
		cin >> answer;

		string carryMode = "Don't use carry mode";
		if (answer == "Yes")
		{
			carryMode = "Use carry mode";
		}

		SaveInPlainText(carryMode);

		cout << endl;
	}
	else if (option == 7)//option seven
	{
		string answer;
		cout << "Do you want to use carry mode?" << endl;
		cin >> answer;

		string carryMode = "Don't use carry mode";
		if (answer == "Yes")
		{
			carryMode = "Use carry mode";
		}

		SaveInJSONFormat(carryMode);

		cout << endl;
	}
}

int main()
{
	ChooseFromMenu();
	while (true)
	{
		cout << "Your choice: ";
		int choice;
		cin >> choice;
		if (choice > 8 || choice < 1)
		{
			cout << "Error! No such variant. Try again." << endl;
			cout << "Your choice: ";
			cin >> choice;
		}
		if (choice == 8)
		{
			cout << "Have a nice day!" << endl;
			break;
		}

		Options(choice);
	}

}
