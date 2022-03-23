/**********************************
**** InputPattern Object cpp File *
***********************************/

#include <stdio.h>
#include "InputPattern.h"
#include "Pattern.h"

class CSVFile;

// InputPattern Constructor
InputPattern::InputPattern()
{
	setT(0.0f);
	setR(0.0f);
	setG(0.0f);
	setB(0.0f);
}

// Overloaded Input Constructor
InputPattern::InputPattern(float t, float r, float g, float b)
{
	setT(t);
	setR(r);
	setG(g);
	setB(b);
}

void InputPattern::setR(float newR)
{
	// error check to ensure t is between -1.0f and +1.0f
	if (newR < -1.0 || newR > 1.0)
	{
		if (this->debug == 1) // set debug in pattern.cpp
		{
			printf("Value r is outside of range -1.0f and 1.0f. Entered time: %.2f\n", newR);
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

	this->r = newR;
}

float InputPattern::getR()
{
	return r;
}

void InputPattern::setG(float newG)
{
	// error check to ensure t is between -1.0f and +1.0f
	if (newG < -1.0 || newG > 1.0)
	{
		if (this->debug == 1) // set debug in pattern.cpp
		{
			printf("Value g is outside of range -1.0f and 1.0f. Entered time: %.2f\n", newG);
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

	this->g = newG;
}

float InputPattern::getG()
{
	return g;
}

void InputPattern::setB(float newB)
{
	// error check to ensure t is between -1.0f and +1.0f
	if (newB < -1.0 || newB > 1.0) // set debug in pattern.cpp
	{
		if (this->debug == 1)
		{
			printf("Value b is outside of range -1.0f and 1.0f. Entered time: %.2f\n", newB);
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

	this->b = newB;
}

float InputPattern::getB()
{
	return b;
}

void InputPattern::setInputPattern(CSVFile* csv)
{
	this->csv = csv;
}

CSVFile * InputPattern::getInputPattern(void)
{
	return csv;
}

void InputPattern::print(int count)
{
	// Test print, use getx() functions to print the return value, rather than using this->x
	printf("\nTime: %.2f\nRed: %.2f\nGreen: %.2f\nBlue: %.2f\nCount: %d\n", getT(), getR(), getG(), getB(), count);
}