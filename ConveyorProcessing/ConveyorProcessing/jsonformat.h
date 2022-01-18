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
	}
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
		int counterForRows = 1;
		int numbersAtOneRow = functionsCount;
		while (in >> number)
		{
			if (counterForElements == 1)//first element
			{
				resultInFile << "\t\t\[" << number << ", ";
			}
			else if (counterForElements == numbersAtOneRow)//last element
			{
				if (counterForRows == functionsCount)
				{
					resultInFile << number << "]" << endl;
					counterForElements = 0;
				}
				else
				{
					resultInFile << number << "]," << endl;
					counterForElements = 0;
					counterForRows++;
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

		while (inNumbers >> number)
		{
			ifstream inFunctions;
			inFunctions.open("functions.txt");
			string function;

			int currentCounter = 1;
			int functionsCount = GetFunctionsCount();

			resultInFile << "\t\t\[";

			while (inFunctions >> function)
			{
				double result = GetResult(function, number);

				if (currentCounter == functionsCount)
				{
					resultInFile << result << "],";
				}
				else
				{
					resultInFile << result << ", ";
				}
				currentCounter++;
			}
			resultInFile << endl;
			inFunctions.close();
		}
		inNumbers.close();

		resultInFile << "\t]," << endl;
		resultInFile << "\t\"byCols\": [" << endl;

		ifstream inFunctions;
		inFunctions.open("functions.txt");
		string function;

		while (inFunctions >> function)
		{
			ifstream inNumbers;
			inNumbers.open("numbers.txt");
			double number;

			int currentCounter = 1;
			int numbersCount = GetNumbersCount();

			resultInFile << "\t\t\[";

			while (inNumbers >> number)
			{
				double result = GetResult(function, number);

				if (currentCounter == numbersCount)
				{
					resultInFile << result << "],";
				}
				else
				{
					resultInFile << result << ", ";
				}
				currentCounter++;
			}
			resultInFile << endl;
			inNumbers.close();
		}
		inFunctions.close();

		resultInFile << "\t]," << endl;
		resultInFile << "}" << endl;

		resultInFile.close();
	}
}
