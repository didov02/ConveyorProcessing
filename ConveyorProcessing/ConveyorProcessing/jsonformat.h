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
* <file to save the matrix in json format>
*
*/

#pragma once

using namespace std;

int GetFunctionsCount()
{
	ifstream in;
	in.open("functions.txt");

	int counter = 0;
	string function;

	while (in >> function)
	{
		counter++;
	}
	in.close();

	return counter;
}

int GetNumbersCount()
{
	ifstream in;
	in.open("numbers.txt");

	int counter = 0;
	double number;

	while (in >> number)
	{
		counter++;
	}
	in.close();

	return counter;
}

void CreateTemporaryFileForTransposedMatrixJSONFormat()
{
	int stepsToGetNeededNumber = GetFunctionsCount();//used only after the first row


	ifstream openFunctions;
	openFunctions.open("functions.txt");
	string function;

	int rows = 1;
	while (openFunctions >> function)
	{
		ifstream openNumbers;
		openNumbers.open("numbers.txt");
		double number;


		while (openNumbers >> number)
		{
			double result = GetResultWithCarryModeForTransposedMatrix(number, function, stepsToGetNeededNumber, rows);

			fstream add;
			add.open("temporary.txt", fstream::app);
			add << result << " ";
			add.close();
		}
		rows++;

		openNumbers.close();
	}

	openFunctions.close();
}

void SaveInJSONFormat(string mode)
{
	std::remove("result_in_JSON_format.txt");

	if (mode == "Use carry mode")
	{
		ifstream inNumbers;
		inNumbers.open("numbers.txt");
		double number;

		ofstream resultInFile;
		resultInFile.open("result_in_JSON_format.txt");

		int functionsCount = GetFunctionsCount();
		int numbersCount = GetNumbersCount();

		resultInFile << "{" << endl;
		resultInFile << "\t\"byRows\": [" << endl;

		int rowsCounter = 1;

		while (inNumbers >> number)
		{
			ifstream inFunctions;
			inFunctions.open("functions.txt");
			string function;

			double numberToSave = 0;
			int currentCounter = 1;

			resultInFile << "\t\t\[";

			while (inFunctions >> function)
			{
				double result = GetResultWithCarryMode(function, number, numberToSave);

				if (currentCounter == functionsCount)
				{
					if (rowsCounter == functionsCount)
					{
						resultInFile << result << "]";
					}
					else
					{
						resultInFile << result << "],";
					}
				}
				else
				{
					resultInFile << result << ", ";
				}

				currentCounter++;
			}

			resultInFile << endl;
			inFunctions.close();

			rowsCounter++;
		}

		inNumbers.close();

		resultInFile << "\t]," << endl;
		resultInFile << "\t\"byCols\": [" << endl;

		CreateTemporaryFileForTransposedMatrixJSONFormat();
		ifstream in;
		in.open("temporary.txt");
		number = 0;
		
		int counterForElements = 1;
		rowsCounter = 1;

		while (in >> number)
		{
			if (counterForElements == 1)//first element
			{
				resultInFile << "\t\t\[" << number << ", ";
			}
			else if (counterForElements == numbersCount)//last element
			{
				if (rowsCounter == functionsCount)
				{
					resultInFile << number << "]" << endl;
					counterForElements = 0;
				}
				else
				{
					resultInFile << number << "]," << endl;
					counterForElements = 0;
					rowsCounter++;
				}
			}
			else
			{
				resultInFile << number << ", ";
			}

			counterForElements++;

		}
		in.close();

		resultInFile << "\t]," << endl;

		resultInFile << "}" << endl;

		resultInFile.close();

		std::remove("temporary.txt");
	}
	else
	{
		ifstream inNumbers;
		inNumbers.open("numbers.txt");
		double number;

		ofstream resultInFile;
		resultInFile.open("result_in_JSON_format.txt");

		resultInFile << "{" << endl;
		resultInFile << "\t\"byRows\": [" << endl;

		int functionsCount = GetFunctionsCount();
		int numbersCount = GetNumbersCount();

		int rowsCounter = 1;

		while (inNumbers >> number)
		{
			ifstream inFunctions;
			inFunctions.open("functions.txt");
			string function;

			int currentCounter = 1;

			resultInFile << "\t\t\[";

			while (inFunctions >> function)
			{
				double result = GetResult(function, number);

				if (currentCounter == functionsCount)
				{
					if (rowsCounter == numbersCount)
					{
						resultInFile << result << "]";
					}
					else
					{
						resultInFile << result << "],";
					}
				}
				else
				{
					resultInFile << result << ", ";
				}

				currentCounter++;
			}

			resultInFile << endl;
			inFunctions.close();

			rowsCounter++;
		}

		inNumbers.close();

		resultInFile << "\t]," << endl;
		resultInFile << "\t\"byCols\": [" << endl;

		ifstream inFunctions;
		inFunctions.open("functions.txt");
		string function;

		rowsCounter = 1;

		while (inFunctions >> function)
		{
			ifstream inNumbers;
			inNumbers.open("numbers.txt");
			double number;

			int currentCounter = 1;

			resultInFile << "\t\t\[";

			while (inNumbers >> number)
			{
				double result = GetResult(function, number);

				if (currentCounter == numbersCount)
				{
					if (rowsCounter == functionsCount)
					{
						resultInFile << result << "]";
					}
					else
					{
						resultInFile << result << "],";
					}
				}
				else
				{
					resultInFile << result << ", ";
				}

				currentCounter++;
			}

			resultInFile << endl;
			inNumbers.close();

			rowsCounter++;
		}

		inFunctions.close();

		resultInFile << "\t]," << endl;
		resultInFile << "}" << endl;

		resultInFile.close();
	}
}
