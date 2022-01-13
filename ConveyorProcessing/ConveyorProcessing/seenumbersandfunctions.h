#pragma once

using namespace std;

void SeeYourNumbers()
{
	ifstream in;
	in.open("numbers.txt");
	if (in.is_open())
	{
		double number;
		while (in >> number)
		{
			cout << number << endl;
		}
	}
	in.close();
	cout << endl;
}

void SeeYourFunctions()
{
	ifstream in;
	in.open("functions.txt");
	if (in.is_open())
	{
		string output;
		while (in >> output)
		{
			cout << output << endl;
		}
	}
	in.close();
	cout << endl;
}
