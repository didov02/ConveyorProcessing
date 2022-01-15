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
	}

	cout << out.str() << endl;

}
