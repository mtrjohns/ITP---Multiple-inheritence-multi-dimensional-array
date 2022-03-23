/***********************************
**** OutputPattern Object cpp File *
************************************/

#include <stdio.h>
#include "OutputPattern.h"
#include "Pattern.h"

class CSVFile;

// Output Constructor
OutputPattern::OutputPattern()
{
	setT(0.0f);
	setO(0.0f);
}

// Overloaded Output Constructor
OutputPattern::OutputPattern(float t, float o)
{
	setT(t);
	setO(o);
}

void OutputPattern::setO(float newO)
{
	// error check to ensure t is between -1.0f and +1.0f
	if (newO < -1.0 || newO > 1.0)
	{
		if (this->debug == 1) // set debug in pattern.cpp
		{
			printf("Value o is outside of range -1.0f and 1.0f. Entered time: %.2f\n", newO);
		}
		else
		{
			// Blank else statement
		}
	}
	else
	{
		// Blank else statement
	}

	this->o = newO;
}

float OutputPattern::getO(void)
{
	return o;
}

void OutputPattern::setOutputPattern(CSVFile* csv)
{
	this->csv = csv;
}

CSVFile * OutputPattern::getOutputPattern(void)
{
	return csv;
}

void OutputPattern::print(int count)
{
	printf("\nTime: %.2f\nOutput: %.2f\nCount: %d\n", getT(), getO(), count);
}