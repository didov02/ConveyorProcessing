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
