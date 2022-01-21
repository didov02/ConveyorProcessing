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
* <file to get the matrix on the screen>
*
*/


#pragma once

using namespace std;

void Matrix()
{
	ifstream inNumbers;
	inNumbers.open("numbers.txt");
	double number;

	ostringstream out;

	while (inNumbers >> number)
	{
		ifstream inFunctions;
		inFunctions.open("functions.txt");
		string function;

		while (inFunctions >> function)
		{
			double result = GetResult(function, number);
			out << result << " ";
		}

		out << endl;

		inFunctions.close();
	}

	cout << out.str() << endl;

	inNumbers.close();

}
