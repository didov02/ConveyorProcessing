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
* <file with functions to overwrite "functions.txt">
*
*/

#pragma once

using namespace std;

void OverwriteFunctionsFile()
{
	ofstream out;
	out.open("functions.txt");
	ifstream in;
	in.open("new_functions.txt");
	string function;
	while (in >> function)
	{
		out << function << endl;
	}
	out.close();
	in.close();

	std::remove("new_functions.txt");
}

void ChangeOneFunction(int lineToChange, string newFunc)
{
	int counter = 0;
	fstream newTextFile;
	ifstream in;
	in.open("functions.txt");
	newTextFile.open("new_functions.txt", fstream::out);
	string function;
	while (in >> function)
	{
		if (counter == lineToChange - 1)
		{
			newTextFile << newFunc << endl;
		}
		else
		{
			newTextFile << function << endl;
		}

		counter++;
	}
	newTextFile.close();
	in.close();

	OverwriteFunctionsFile();
}
