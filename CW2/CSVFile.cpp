/*****************************
**** CSVFile Object cpp File *
*****************************/

#include "CSVFile.h"
#include "InputPattern.h"
#include "OutputPattern.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

CSVFile::CSVFile()
{
	setName("NoNameSet");
	setLoadedFlagFalse();
	patternCount = 0;
	filePatternCount = 0;
}

CSVFile::CSVFile(char * filename)
{
	setName(filename);
	setLoadedFlagFalse();
	patternCount = 0;
	filePatternCount = 0;
}

CSVFile::~CSVFile()
{
	int i;

	for (i = 0; i<filePatternCount; i++)
	{

		if (inputs[i] != nullptr)
		{
			delete(inputs[i]);
			inputs[i] = nullptr;
		}
		delete[] *inputs;
	}
	for (i = 0; i<filePatternCount; i++)
	{
		if (outputs[i] != nullptr)
		{
			delete(outputs[i]);
			outputs[i] = nullptr;
		}
		delete[] *outputs;
	}
}

void CSVFile::setName(char * filename)
{
	strcpy_s(this->name, filename);
}

char* CSVFile::getName(void)
{
	return name;
}

void CSVFile::getFilename(char * outBuff, int outBuffSize)
{
	// not sure what this method is for, used setname 
}

void CSVFile::setLoadedFlagTrue()
{
	this->loadedFlag = true;
}

void CSVFile::setLoadedFlagFalse()
{
	this->loadedFlag = false;
}

bool CSVFile::getLoadedFlag()
{
	return loadedFlag;
}

int CSVFile::loadFile()
{
	ifstream file(this->getName());
	/* Testing only:
	cout << "File name: " << getName() << endl;
	*/

	string line;
	string inputStore[NAME_MAX];

	unsigned int index = 0;
	unsigned int counter = 0;
	unsigned int i = 0;
	float floatStore1 = 0.0f;
	float floatStore2 = 0.0f;
	float floatStore3 = 0.0f;
	float floatStore4 = 0.0f;

	if (!file.is_open())
	{
		printf("Error opening file correctly\n");
		setLoadedFlagFalse();
	}
	else
	{
		setLoadedFlagTrue();
		// while /n has not been reached in file
		while (getline(file, line))
		{
			stringstream patternStore(line);
			stringstream field(line);
			string cell;

			// while comma has not been reached in file
			while (getline(patternStore, cell, ','))
			{
				// while comma has not been reached within field
				getline(field, inputStore[index], ',');

				/* Testing only:
				// had to use c++ cout function as printf would not print out the values from file
				cout << "inputStore[" << index << "]" << inputStore[index] << "\n";
				/*/

				index++;
			}
		}

		// Set Pattern Variables
		istringstream(inputStore[2]) >> this->filePatternCount;
		istringstream(inputStore[4]) >> this->inputPatternLength;
		istringstream(inputStore[6]) >> this->outputPatternLength;

		index = 7;

		// Fill Input and Output patterns
		while (counter < this->filePatternCount)
		{
			// Set Input Patterns
			stringstream t(inputStore[index]);
			t >> floatStore1;
			/* Testing only:
			cout << "Original Value = " << inputStore[index] << ", index[" << index << "] = " << floatStore1 << endl;
			*/
			index++;

			stringstream r(inputStore[index]);
			r >> floatStore2;
			/* Testing only:
			cout << "Original Value = " << inputStore[index] << ", index[" << index << "] = " << floatStore2 << endl;
			*/
			index++;

			stringstream g(inputStore[index]);
			g >> floatStore3;
			/* Testing only:
			cout << "Original Value = " << inputStore[index] << ", index[" << index << "] = " << floatStore3 << endl;
			*/
			index++;

			stringstream b(inputStore[index]);
			b >> floatStore4;
			/* Testing only:
			cout << "Original Value = " << inputStore[index] << ", index[" << index << "] = " << floatStore4 << endl;
			*/
			index++;
			
			inputs[counter] = new InputPattern(floatStore1, floatStore2, floatStore3, floatStore4);

			/* Testing only: 
			cout << "Value in inputpattern[" << counter << "] getR() = " << inputs[counter]->getR() << endl;
			cout << "Value in inputpattern[" << counter << "] getG() = " << inputs[counter]->getG() << endl;
			cout << "Value in inputpattern[" << counter << "] getB() = " << inputs[counter]->getB() << endl;
			cout << "Value in inputpattern[" << counter << "] getT() = " << inputs[counter]->getT() << endl;
			*/

			// Set Output patterns
			stringstream tO(inputStore[index]);
			tO >> floatStore1;
			/* Testing only:
			cout << "Original Value = " << inputStore[index] << ", index[" << index << "] = " << floatStore1 << endl;
			*/
			index++;

			stringstream o(inputStore[index]);
			o >> floatStore2;
			/* Testing only:
			cout << "Original Value = " << inputStore[index] << ", index[" << index << "] = " << floatStore2 << endl;
			*/
			index++;

			outputs[counter] = new OutputPattern(floatStore1, floatStore2);
			/* Testing only:
			cout << "Value in outputpattern[" << counter << "] getT() = " << outputs[counter]->getT() << endl;
			cout << "Value in outputpattern[" << counter << "] getO() = " << outputs[counter]->getO() << endl;
			*/

			counter++;
		}
	}

	file.close();
	for (i = 0; i < filePatternCount; i++)
	{
		inputStore[i].clear();
	}
		
	return 0;
}

InputPattern * CSVFile::getInputPattern(int index)
{
	if (index > -1 && index < this->filePatternCount || index == 0)
	{
		return inputs[index];
	}
	else
	{
		// Blank Else Statement
		return nullptr;
	}
}

OutputPattern * CSVFile::getOutputPattern(int index)
{
	if (index > -1 && index < this->filePatternCount || index == 0)
	{
		return outputs[index];
	}
	else
	{
		// Blank Else Statement
		return nullptr;
	}
}

void CSVFile::addInputPattern(InputPattern * in)
{
	{
		if (patternCount < NAME_MAX)
		{
			// Add input pattern
			inputs[patternCount] = in;
			//increment counter [patternCount]
			patternCount++;
			//set this as the inputs csvfile
			in->setInputPattern(this);
		}
		else
		{
			// Blank else statement
		}
	}
}

void CSVFile::addOutputPattern(OutputPattern * out)
{
	if (patternCount < NAME_MAX)
	{
		// Add Output pattern
		outputs[patternCount] = out;
		//increment counter
		patternCount++;
		//set this as the inputs csvfile
		out->setOutputPattern(this);
	}
	else
	{
		// Blank else statement
	}
}

void CSVFile::printMetaData()
{
	cout << "Pattern Count: " << filePatternCount << endl;
	cout << "Output Pattern Count: " << outputPatternLength << endl;
	cout << "Input Pattern Count: " << inputPatternLength << endl;
}

void CSVFile::printPatterns()
{
	cout << endl << "\t\tInput Patterns\t\t\t\tOutput Patterns" << endl;
	cout << "Pattern\t\tT\tR\tG\tB\t\tT\tO" << endl;

	for (int i = 0; i < filePatternCount; i++)
	{
		cout << i << "\t\t" << getInputPattern(i)->getT() << "\t"
			<< getInputPattern(i)->getR() << "\t"
			<< getInputPattern(i)->getG() << "\t"
			<< getInputPattern(i)->getB() << "\t\t"
			<< getOutputPattern(i)->getT() << "\t"
			<< getOutputPattern(i)->getO() << endl;
	}

	cout << endl;
}