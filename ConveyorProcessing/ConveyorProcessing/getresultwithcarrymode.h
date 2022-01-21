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
* <file with functions to get the matrix with carry mode>
*
*/

#pragma once

double GetResultWithCarryMode(string func, double num, double& savedNum)
{
	char symbol = func[0];//the first element of our function
	string number = "";//the number we get from our current function
	if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '%')
	{
		for (int i = 1; i < func.length(); i++)
		{
			number += func[i];
		}
	}
	else if (symbol == '<' || symbol == '>')
	{
		for (int i = 2; i < func.length(); i++)
		{
			number += func[i];
		}
	}

	double convertedNumber = 0;// the number we get from our function converted in double
	stringstream convert(number);
	convert >> convertedNumber;

	bool isConvertedNumberInteger = true;
	if (convertedNumber != (int)convertedNumber)
	{
		isConvertedNumberInteger = false;
	}

	bool isNumInteger = true;
	if (num != (int)num)
	{
		isNumInteger = false;
	}

	double result = 0;
	if (symbol == '+')
	{
		result = (num + savedNum) + convertedNumber;
	}
	else if (symbol == '-')
	{
		result = (num + savedNum) - convertedNumber;
	}
	else if (symbol == '*')
	{
		result = (num + savedNum) * convertedNumber;
	}
	else if (symbol == '/')
	{
		result = (num + savedNum) / convertedNumber;
	}
	else if (symbol == '%')
	{
		if (isConvertedNumberInteger == true && isNumInteger == true
			&& num > 0 && convertedNumber > 0)
		{
			result = ((int)num + (int)savedNum) % (int)convertedNumber;
		}
		else
		{
			result = 0;
		}
	}
	else if (symbol == '<')
	{
		if (isConvertedNumberInteger == true && isNumInteger == true && convertedNumber > 0)
		{
			result = (num + savedNum) * (pow(2, convertedNumber));
		}
		else
		{
			result = 0;
		}
	}
	else if (symbol == '>')
	{
		if (isConvertedNumberInteger == true && isNumInteger == true && convertedNumber > 0)
		{
			result = (num + savedNum) / (pow(2, convertedNumber));
		}
		else
		{
			result = 0;
		}
	}

	savedNum = result;
	return result;
}

double GetResultWithCarryModeForTransposedMatrix(double num, string func, int steps, int row)
{
	double result = 0;

	bool doWeNeedSavedNum = false;
	if (row > 1)
	{
		doWeNeedSavedNum = true;
	}

	if (doWeNeedSavedNum == true)
	{
		int numbersCount = 1;
		ifstream read;
		read.open("temporary.txt");
		double numberToRead;

		while (read >> numberToRead)
		{
			numbersCount++;
		}

		read.close();

		ifstream readAgain;
		readAgain.open("temporary.txt");
		int neededNumberPosition = numbersCount - steps;
		double neededNumber = 0;
		int counter = 1;
		while (readAgain >> numberToRead)
		{
			if (counter == neededNumberPosition)
			{
				neededNumber = numberToRead;
				break;
			}
			counter++;
		}
		readAgain.close();

		char symbol = func[0];//the first element of our function
		string number = "";//the number we get from our current function
		if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '%')
		{
			for (int i = 1; i < func.length(); i++)
			{
				number += func[i];
			}
		}
		else if (symbol == '<' || symbol == '>')
		{
			for (int i = 2; i < func.length(); i++)
			{
				number += func[i];
			}
		}

		double convertedToNumber = 0;// the number we get from our function converted in double
		stringstream convert(number);
		convert >> convertedToNumber;

		bool isConvertedNumberInteger = true;
		if (convertedToNumber != (int)convertedToNumber)
		{
			isConvertedNumberInteger = false;
		}

		bool isNumInteger = true;
		if (num != (int)num)
		{
			isNumInteger = false;
		}

		double result = 0;
		if (symbol == '+')
		{
			result = (num + neededNumber) + convertedToNumber;
		}
		else if (symbol == '-')
		{
			result = (num + neededNumber) - convertedToNumber;
		}
		else if (symbol == '*')
		{
			result = (num + neededNumber) * convertedToNumber;
		}
		else if (symbol == '/')
		{
			result = (num + neededNumber) / convertedToNumber;
		}
		else if (symbol == '%')
		{
			if (isConvertedNumberInteger == true && isNumInteger == true
				&& num > 0 && convertedToNumber > 0)
			{
				result = ((int)num + (int)neededNumber) % (int)convertedToNumber;
			}
			else
			{
				result = 0;
			}
		}
		else if (symbol == '<')
		{
			if (isConvertedNumberInteger == true && isNumInteger == true && convertedToNumber > 0)
			{
				result = (num + neededNumber) * (pow(2, convertedToNumber));
			}
			else
			{
				result = 0;
			}
		}
		else if (symbol == '>')
		{
			if (isConvertedNumberInteger == true && isNumInteger == true && convertedToNumber > 0)
			{
				result = (num + neededNumber) / (pow(2, convertedToNumber));
			}
			else
			{
				result = 0;
			}
		}

		return result;
	}
	else if (doWeNeedSavedNum == false)
	{
		result = GetResult(func, num);

		return result;
	}


}
