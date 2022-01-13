#include <iostream>
#include<string>
#include<cmath>
#include<fstream>
#include<sstream>
#include "seenumbersandfunctions.h"
#include "changeonenumber.h"

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
