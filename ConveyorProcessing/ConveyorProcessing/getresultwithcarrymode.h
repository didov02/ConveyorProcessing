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
