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
* <file with function to get matrix's result>
*
*/

#pragma once

using namespace std;

double GetResult(string func, double num)//for our matrix
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
		result = num + convertedNumber;
	}
	else if (symbol == '-')
	{
		result = num - convertedNumber;
	}
	else if (symbol == '*')
	{
		result = num * convertedNumber;
	}
	else if (symbol == '/')
	{
		result = num / convertedNumber;
	}
	else if (symbol == '%')
	{
		if (isConvertedNumberInteger == true && isNumInteger == true
			&& num > 0 && convertedNumber > 0)
		{
			result = (int)num % (int)convertedNumber;
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
			result = num * (pow(2, convertedNumber));
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
			result = num / (pow(2, convertedNumber));
		}
		else
		{
			result = 0;
		}
	}

	return result;
}
