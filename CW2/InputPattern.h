#pragma once
/*************************************
**** InputPattern Object Header File *
*************************************/

#include "Pattern.h"
class CSVFile;

class InputPattern : public Pattern
{
private:
	float r = 0.0f;
	float g = 0.0f;
	float b = 0.0f;
	CSVFile* csv;

public:
	InputPattern();
	InputPattern(float, float, float, float);

	void setR(float);
	float getR();
	void setG(float);
	float getG();
	void setB(float);
	float getB();

	void setInputPattern(CSVFile*);
	CSVFile* getInputPattern(void);

	void print(int);
};