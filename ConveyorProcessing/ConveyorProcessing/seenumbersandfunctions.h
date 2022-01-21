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
* <file with function to see numbers on the screen>
*
*/

#pragma once

using namespace std;

void SeeYourNumbers()
{
	ifstream in;
	in.open("numbers.txt");
	if (in.is_open())
	{
		double number;
		while (in >> number)
		{
			cout << number << endl;
		}
	}

	in.close();
	cout << endl;
}

void SeeYourFunctions()
{
	ifstream in;
	in.open("functions.txt");
	if (in.is_open())
	{
		string output;
		while (in >> output)
		{
			cout << output << endl;
		}
	}

	in.close();
	cout << endl;
}
