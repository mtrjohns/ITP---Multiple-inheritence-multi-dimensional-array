/*****************************
**** Pattern Object cpp File *
*****************************/

#include <stdio.h>
#include "Pattern.h"

Pattern::Pattern()
{
	// setDebug -	(0) = debug disabled
	//				(1) = display values out of the range of -1.0f and 1.0f
	setDebug(0);
	setT(0.0f);
}

Pattern::Pattern(float t)
{
	setT(t);
}


Pattern::~Pattern()
{
	// check for object destructing in test harness
	if (getDebug() == 1) // set debug in pattern.cpp
	{
		
		printf("Destructor called correctly for Pattern\n");
	}
	else
	{
		// Blank else statement
	}
	
}

void Pattern::setT(float newT)
{
	// error check to ensure t is between -1.0f and +1.0f
	if (newT < -1.0 || newT > 1.0)
	{
		if (getDebug() == 1) // set debug in pattern.cpp
		{
			printf("Value t is outside of range -1.0f and 1.0f. Entered time: %.2f\n", newT);
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

	this->t = newT;
}

float Pattern::getT()
{
	return t;
}

void Pattern::setDebug(int newDebug)
{
	this->debug = newDebug;
}

int Pattern::getDebug()
{
	return debug;
}

