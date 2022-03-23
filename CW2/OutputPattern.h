#pragma once
/*************************************
**** OutputPattern Object Header File *
*************************************/

#include "Pattern.h"
class CSVFile;

class OutputPattern : public Pattern
{

private:
	float o = 0.0f;
	CSVFile* csv;
public:
	OutputPattern();
	OutputPattern(float, float);

	void setO(float);
	float getO(void);

	void setOutputPattern(CSVFile*);
	CSVFile* getOutputPattern(void);

	void print(int);
};