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
* <file with functions to overwrite "number.txt">
*
*/

#pragma once

using namespace std;

void OverwriteNumbersFile()
{
	ofstream out;
	out.open("numbers.txt");
	ifstream in;
	in.open("new_numbers.txt");
	double number;
	while (in >> number)
	{
		out << number << endl;
	}
	out.close();
	in.close();

	std::remove("new_numbers.txt");

}

void ChangeOneNumber(int lineToChange, int newNum)
{
	int counter = 0;//counter for lines
	fstream newTextFile;
	ifstream in;
	in.open("numbers.txt");
	newTextFile.open("new_numbers.txt", fstream::out);
	double number;
	while (in >> number)
	{
		if (counter == lineToChange - 1)
		{
			newTextFile << newNum << endl;
		}
		else
		{
			newTextFile << number << endl;
		}

		counter++;
	}
	newTextFile.close();
	in.close();

	OverwriteNumbersFile();
}

