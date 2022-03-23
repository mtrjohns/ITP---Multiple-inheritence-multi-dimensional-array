/****************************
*** Test Harness header *****
****************************/

#pragma once

class TestHarness
{


public:
	TestHarness(void);
	~TestHarness(void);

	bool testInputPattern();
	bool testOutputPattern();
	bool testCSVFile();

private:
	bool testInputPatternCreate();
	bool testInputPatternSetup();
	bool testInputPatternCreateWithParameters();
	bool testInputPatternsDestroy();
    bool testInputPatternsPrint();

	bool testOutputPatternCreate();
	bool testOutputPatternSetup();
	bool testOutputPatternCreateWithParameters();
	bool testOutputPatternsDestroy();
	bool testOutputPatternsPrint();

	bool testCSVFileCreate();
    bool testCSVFileSetFilepath();
    bool testCSVFileLoadedFlag();
	bool testCSVFileAddGetInputPattern();
	bool testCSVFileAddGetOutputPattern();
    bool testCSVFileLoadFile();
	bool testCSVFilePrintMeta();
    bool testCSVFilePrintPatterns();
};

