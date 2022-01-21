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
* <file to save the matrix in .txt>
*
*/

#pragma once

using namespace std;

void SaveInPlainText(string mode)
{
	if (mode == "Use carry mode")
	{
		ifstream inNumbers;
		inNumbers.open("numbers.txt");
		double number;

		ofstream resultInFile;
		resultInFile.open("result.txt");

		while (inNumbers >> number)
		{
			ifstream inFunctions;
			inFunctions.open("functions.txt");
			string function;

			double numberToAdd = 0;

			while (inFunctions >> function)
			{
				double result = GetResultWithCarryMode(function, number, numberToAdd);
				resultInFile << result << " ";
			}

			resultInFile << endl;
			inFunctions.close();
		}

		resultInFile.close();
	}
	else
	{
		ifstream inNumbers;
		inNumbers.open("numbers.txt");
		double number;

		ofstream resultInFile;
		resultInFile.open("result.txt");

		while (inNumbers >> number)
		{
			ifstream inFunctions;
			inFunctions.open("functions.txt");
			string function;

			while (inFunctions >> function)
			{
				double result = GetResult(function, number);
				resultInFile << result << " ";
			}

			resultInFile << endl;
			inFunctions.close();
		}

		resultInFile.close();
	}
}
