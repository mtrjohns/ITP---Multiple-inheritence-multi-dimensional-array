#pragma once

/********************************
**** CSVFile Object Header File *
********************************/


class InputPattern;
class OutputPattern;

class CSVFile
{
private:
	// Maximum storage value
	static const unsigned int NAME_MAX = 128;
	// Array to store file name
	char name[NAME_MAX];
	bool loadedFlag;

	InputPattern* inputs[NAME_MAX];
	OutputPattern* outputs[NAME_MAX];
	// Stores total patterns
	int patternCount;
	// Stores total string array count from file (within inputStore in loadfile()  )
	int filePatternCount;
	// Stores input pattern count from file
	int inputPatternLength;
	// Stores output pattern count from file
	int outputPatternLength;

public:

	CSVFile();
	CSVFile(char*);
	~CSVFile();

	void setName(char*);
	char* getName(void);
	void getFilename(char*, int);

	void setLoadedFlagTrue();
	void setLoadedFlagFalse();
	bool getLoadedFlag();

	int loadFile();

	InputPattern* getInputPattern(int);
	OutputPattern* getOutputPattern(int);

	void addInputPattern(InputPattern*);
	void addOutputPattern(OutputPattern*);

	void printMetaData();
	void printPatterns();

};

