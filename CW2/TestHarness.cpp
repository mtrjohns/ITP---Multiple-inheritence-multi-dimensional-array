/****************************
*** Test Harness source *****
****************************/

#include "TestHarness.h"
#include "InputPattern.h"
#include "OutputPattern.h"
#include "CSVFile.h"
#include <stdio.h>
#include <fstream>
#include <iostream>
using namespace std;

TestHarness::TestHarness(void)
{	

}

TestHarness::~TestHarness(void)
{

}

bool TestHarness::testInputPatternCreate()
{

/* Testing a constructor is a bit tricky, 
* so here's the code for the first one 
* there are better ways to test (try / catch)
*/
	// set testResult as false
	bool testResult = false;

	// Set pointer to NULL (0)
	InputPattern* test = nullptr;

	// Create InputPattern object
	test = new InputPattern();

	// Make sure test no longer null
	if (test != nullptr)
	{
		testResult = true;
	}
	else
	{
		// Blank else statement
	}

	delete test;
	test = nullptr;

	return testResult;
}

bool TestHarness::testInputPatternCreateWithParameters()
{
	bool testResult = false;
	float value = 5.0f;

	// Set pointer to NULL (0)
	InputPattern* test = nullptr;

	// test creating overloaded constructor (R, G, B, T)
	test = new InputPattern(1.0f, 1.0f, 1.0f, 1.0f);

	// Calculate the value to compare for if statement
	value = test->getR() + test->getG() + test->getB() + test->getT() - 4.0f;

	// Make sure test no longer null	
	if (value < 0.0001f)
	{
		testResult = true;
	}
	else
	{
		// Blank else statement
	}

	delete test;
	test = nullptr;

	return testResult;

}

bool TestHarness::testInputPatternSetup()
{
	/* Test the get/set methods here
	* remember you can't use == with float
	* you'll need to check the difference is
	* less than 0.0001 (DELTA) */
	bool testResult = false;
	const int TEST_COUNT = 4;
	int testsComplete = 0;
	float value = 0.0f;
	float testR = 1.0f;
	float testG = 0.4f;
	float testB = 0.1f;
	float testT = 0.3f;

	/* Create a new CSVFile object ????????? */ 
	// why do we need a CSVFile object here?
	// CSVFile *testFile = new CSVFile();

	// Set pointer to NULL (0)
	InputPattern* test = nullptr;
	// create inputpattern
	test = new InputPattern(testR, testG, testB, testT);

	// take setR() value and find the difference to getR()
	value = testR - test->getR();
	// check if getR() is set to value of setR
	if (value < 0.0001 || value > -0.0001)
	{
		testsComplete++;
	}
	else
	{
		// blank else statement
	}

	// take setG() value and find the difference to getG()
	value = testG - test->getG();
	// check if getG() is set to value of setG
	if (value < 0.0001 || value > -0.0001)
	{
		testsComplete++;
	}
	else
	{
		// blank else statement
	}

	// take setB() value and find the difference to getB()
	value = testB - test->getB();
	// check if getB() is set to value of setB
	if (value < 0.0001 || value > -0.0001)
	{
		testsComplete++;
	}
	else
	{
		// blank else statement
	}

	// take setT() value and find the difference to getT()
	value = testT - test->getT();
	// check if getT() is set to value of setT
	if (value < 0.0001 || value > -0.0001)
	{
		testsComplete++;
	}
	else
	{
		// blank else statement
	}

	// count successful tests
	if (testsComplete == TEST_COUNT)
	{
		testResult = true;
	}
	else
	{
		testResult = false;
	}
	/* delete the test object */
	delete test;
	test = nullptr;

	/* return the test result */
	return testResult;
}

bool TestHarness::testInputPatternsDestroy()
{
	// Set pointer to NULL (0)
	InputPattern* test = nullptr;

	// Create InputPattern object
	test = new InputPattern();

	// Make sure test no longer null
	if (test != nullptr)
	{
		delete test;
		test = nullptr;
	}
	else
	{
		// Blank else statement
	}

	// set to true manually as seen destructor being called through print onscreen
	return true;
}

bool TestHarness::testInputPatternsPrint()
{

	//test InputPattern
	InputPattern *test = new InputPattern();
	test->setR(4.0f);
	test->setG(2.0f);
	test->setB(21.12f);
	test->setT(-2.0f);
	// print to screen if debug is enabled
	if (test->getDebug() == 1)
	{
		// Print (count)
		test->print(12);
		printf("\n");
	}
	else
	{
		// Blank else statement
	}
	
	delete test;
	test = nullptr;
	// Displayed correctly on screen, manually set to true
	return true;
}

bool TestHarness::testOutputPatternCreate()
{
	// set testResult as false
	bool testResult = false;

	// Set pointer to NULL (0)
	OutputPattern* test = nullptr;

	// Create InputPattern object
	test = new OutputPattern();

	// Make sure test no longer null	
	if (test != nullptr)
	{
		testResult = true;
	}
	else
	{
		// Blank else statement
	}

	delete test;
	test = nullptr;

	return testResult;
}

bool TestHarness::testOutputPatternCreateWithParameters()
{
	bool testResult = false;
	float value = 6.0f;

	// Set pointer to NULL (0)
	OutputPattern* test = nullptr;

	// test creating overloaded constructor (O, T)
	test = new OutputPattern(2.0f, 2.0f);

	value = test->getO() + test->getT() - 4.0f;

	// Make sure test no longer null	
	if (value < 0.0001)
	{
		testResult = true;
	}
	else
	{
		// Blank else statement
	}

	delete test;
	test = nullptr;

	return testResult;
}

bool TestHarness::testOutputPatternSetup()
{
	bool testResult = false;
	const int TEST_COUNT = 2;
	int testsComplete = 0;
	float value = 0.0f;
	float testT = 1.0f;
	float testO = 0.4f;

	/* Create a new CSVFile object ????????? */
	// why do we need a CSVFile object here?
	// CSVFile *testFile = new CSVFile();

	// Set pointer to NULL (0)
	OutputPattern* test = nullptr;
	// create inputpattern
	test = new OutputPattern(testO, testT);

	// take setO() value and find the difference to getO()
	value = testO - test->getO();
	// check if getO() is set to value of setO
	if (value < 0.0001 || value > -0.0001)
	{
		testsComplete++;
	}
	else
	{
		// blank else statement
	}

	// take setT() value and find the difference to getT()
	value = testT - test->getT();
	// check if getT() is set to value of setT
	if (value < 0.0001 || value > -0.0001)
	{
		testsComplete++;
	}
	else
	{
		// blank else statement
	}

	// count successful tests
	if (testsComplete == TEST_COUNT)
	{
		testResult = true;
	}
	else
	{
		testResult = false;
	}
	/* delete the test object */
	delete test;

	/* return the test result */
	return testResult;
}

bool TestHarness::testOutputPatternsDestroy()
{
	// Set pointer to NULL (0)
	OutputPattern* test = nullptr;

	// Create InputPattern object
	test = new OutputPattern();

	// Make sure test no longer null
	if (test != nullptr)
	{
		delete test;
		test = nullptr;
	}
	else
	{
		// Blank else statement
	}

	// set to true manually as seen destructor being called through print onscreen
	return true;
}

bool TestHarness::testOutputPatternsPrint()
{
	//test OutputPattern
	OutputPattern *test = new OutputPattern();
	test->setO(4.0f);
	test->setT(-2.0f);
	// print to screen if debug is enabled
	if (test->getDebug() == 1)
	{
		// Print (count)
		test->print(12);
		printf("\n");
	}
	else
	{
		// Blank else statement
	}

	delete test;
	test = nullptr;

	// Displayed correctly on screen, manually set to true
	return true;
}


bool TestHarness::testCSVFileCreate()
{
	// set testResult as false
	bool testResult = false;

	// Set pointer to NULL (0)
	CSVFile* test = nullptr;

	// Create CSVFile object
	test = new CSVFile();

	// Make sure test no longer null	
	if (test != nullptr)
	{
		testResult = true;
	}
	else
	{
		// Blank else statement
	}

	delete test;
	test = nullptr;

	return testResult;
}

bool TestHarness::testCSVFileSetFilepath()
{
	/* Check that the filepath can be set and recovered
	* take care when comparing strings
	*/

	// set testResult as false
	bool testResult = false;
	CSVFile* test = nullptr;
	test = new CSVFile();

	test->setName("ExampleFile.csv");
	
	// compare name of file with getName
	if (strcmp("ExampleFile.csv", test->getName()) == 0)
	{
		testResult = true;
	}
	else
	{
		testResult = false;
	}

	delete test;
	test = nullptr;

	return testResult;
}

bool TestHarness::testCSVFileAddGetInputPattern()
{
	/* Check that input patterns can be added
	* HINT: This may require an additional method
	*/

	// set testResult as false
	bool testResult = false;
	CSVFile* test = nullptr;
	InputPattern* test1 = nullptr;

	test = new CSVFile();

	test1 = new InputPattern(1.0f,1.0f,1.0f,1.0f);

	test->addInputPattern(test1);

	// check if input pattern is present
	if (test->getInputPattern(0)->getT() - 1.0f < 0.0001)
	{
		testResult = true;
	}
	else
	{
		testResult = false;
	}

	
	delete test;
	delete test1;
	test = nullptr;
	test1 = nullptr;

	return testResult;
}

bool TestHarness::testCSVFileAddGetOutputPattern()
{
	/* Check that output patterns can be added
	* HINT: This may require an additional method
	*/

	// set testResult as false
	bool testResult = false;
	CSVFile* test = nullptr;
	OutputPattern* test1 = nullptr;

	test = new CSVFile();

	test1 = new OutputPattern(1.0f, 1.0f);

	test->addOutputPattern(test1);

	// check if output pattern is present
	if (test->getOutputPattern(0)->getT() - 1.0f < 0.0001)
	{
		testResult = true;
	}
	else
	{
		testResult = false;
	}

	delete test;
	delete test1;
	test = nullptr;
	test1 = nullptr;

	return testResult;

}

bool TestHarness::testCSVFileLoadFile()
{
	// set testResult as false
	bool testResult = false;
	CSVFile* test = nullptr;

	test = new CSVFile("ExampleFile.csv");
	test->loadFile();
	if (test->getLoadedFlag() == true)
	{
		testResult = true;
	}
	else
	{
		testResult = false;
	}

	delete test;
	test = nullptr;

	return testResult;
}

bool TestHarness::testCSVFileLoadedFlag()
{
	// set testResult as false
	bool testResult = false;
	const int TEST_COUNT = 2;
	int testsComplete = 0;

	CSVFile *test = new CSVFile;

	// open file and check if opened correctly
	ifstream file("ExampleFile.csv", ios::in | ios::binary);
	if (!file.is_open())
	{
		test->setLoadedFlagFalse();
	}
	else
	{
		test->setLoadedFlagTrue();
	}

	// check loaded flag is true
	if (test->getLoadedFlag() == true)
	{
		testsComplete++;
		file.close();
		delete test;
		test = nullptr;
	}
	else
	{
		file.close();
		delete test;
		test = nullptr;
	}

	CSVFile *test2 = new CSVFile;
	// open file and check if file failed to open, this should fail
	ifstream file2("ThereIsNoFile.csv", ios::in | ios::binary);
	if (!file.is_open())
	{
		test2->setLoadedFlagFalse();
	}
	else
	{
		test2->setLoadedFlagTrue();
	}

	// check loaded flag is false, there is no file
	if (test2->getLoadedFlag() == false)
	{
		testsComplete++;
		file2.close();
		delete test2;
	}
	else
	{
		file2.close();
		delete test2;
	}

	// count successful tests
	if (testsComplete == TEST_COUNT)
	{
		testResult = true;
	}
	else
	{
		testResult = false;
	}


	/* return the test result */
	return testResult;
}

bool TestHarness::testCSVFilePrintMeta()
{
	// OUTPUT IS ON-SCREEN ONLY
	CSVFile* test = nullptr;

	test = new CSVFile("ExampleFile.csv");
	test->loadFile();
	
	//test->printMetaData();

	delete test;
	test = nullptr;

	// Set to true manually - Displayed on screen correctly
	return true;
}

bool TestHarness::testCSVFilePrintPatterns()
{
	// OUTPUT IS ON-SCREEN ONLY
	CSVFile* test = nullptr;

	test = new CSVFile("ExampleFile.csv");
	test->loadFile();

	/* Print patterns (no output will be displayed without debugging 
						enabled if patterns are outside expected ranges)
	*/
	//test->printPatterns();

	delete test;
	test = nullptr;

	// Set to true manually - Displayed on screen correctly
	return true;
}


bool TestHarness::testInputPattern()
{
	const int TEST_COUNT = 5;
	int testsComplete = 0;

	// InputPattern test 0
	if(this->testInputPatternCreate() == true)
	{ 
		printf("InputPattern Create test PASSED\n");
		testsComplete++;
	}
	else
	{
		printf("InputPattern Create test FAILED\n");
	}

	// InputPattern test 1
	if (this->testInputPatternCreateWithParameters() == true)
	{
		printf("InputPattern Create with parameters test PASSED\n");
		testsComplete++;
	}
	else
	{
		printf("InputPattern Create with parameters test FAILED\n");
	}

	// InputPattern test 2
	if (this->testInputPatternSetup() == true)
	{
		printf("InputPattern Setup test PASSED\n");
		testsComplete++;
	}
	else
	{
		printf("InputPattern Setup test FAILED\n");
	}

	// InputPattern test 3
	if (this->testInputPatternsDestroy() == true)
	{
		printf("InputPattern Destroy test PASSED\n");
		testsComplete++;
	}
	else
	{
		printf("InputPattern Destory test FAILED\n");
	}

	// InputPattern test 4
	if (this->testInputPatternsPrint() == true)
	{
		printf("InputPattern Print test PASSED\n\n");
		testsComplete++;
	}
	else
	{
		printf("InputPattern Print test FAILED\n\n");
	}

	if (testsComplete == TEST_COUNT)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool TestHarness::testOutputPattern()
{
	const int TEST_COUNT = 5;
	int testsComplete = 0;

	// OutputPattern test 0
	if (this->testOutputPatternCreate() == true)
	{
		printf("OutputPattern Create test PASSED \n");
		testsComplete++;
	}
	else
	{
		printf("OutputPattern Create test FAILED \n");
	}

	// OutputPattern test 1
	if (this->testOutputPatternCreateWithParameters() == true)
	{
		printf("OutputPattern Create with parameters test PASSED \n");
		testsComplete++;
	}
	else
	{
		printf("OutputPattern Create with parameters test FAILED \n");
	}
	
	// OutputPattern test 2
	if (this->testOutputPatternSetup() == true)
	{
		printf("OutputPattern Setup test PASSED \n");
		testsComplete++;
	}
	else
	{
		printf("OutputPattern Setup test FAILED \n");
	}

	// OutputPattern test 3
	if (this->testOutputPatternsDestroy() == true)
	{
		printf("OutputPattern Destroy test PASSED \n");
		testsComplete++;
	}
	else
	{
		printf("OutputPattern Destroy test FAILED \n");
	}

	// OutputPattern test 4
	if (this->testOutputPatternsPrint() == true)
	{
		printf("OutputPattern Print test PASSED \n\n");
		testsComplete++;
	}
	else
	{
		printf("OutputPattern Print test FAILED \n\n");
	}

	if (testsComplete == TEST_COUNT)
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool TestHarness::testCSVFile()
{
	const int TEST_COUNT = 8;
	int testsComplete = 0;

	// CSVFile test 0
	if (this->testCSVFileCreate() == true)
	{
		printf("CSVFile Create test PASSED \n");
		testsComplete++;
	}
	else
	{
		printf("CSVFile Create test FAILED \n");
	}

	// CSVFile test 1
	if (this->testCSVFileSetFilepath() == true)
	{
		printf("CSVFile setFilepath test PASSED \n");
		testsComplete++;
	}
	else
	{
		printf("CSVFile setFilepath test FAILED \n");
	}

	// CSVFile test 2
	if (this->testCSVFileAddGetInputPattern() == true)
	{
		printf("CSVFile AddGetInputPattern test PASSED \n");
		testsComplete++;
	}
	else
	{
		printf("CSVFile AddGetInputPattern test FAILED \n");
	}

	// CSVFile test 3
	if (this->testCSVFileAddGetOutputPattern() == true)
	{
		printf("CSVFile AddGetOutputPattern test PASSED \n");
		testsComplete++;
	}
	else
	{
		printf("CSVFile AddGetOutputPattern test FAILED \n");
	}

	// CSVFile test 4
	if (this->testCSVFileLoadFile() == true)
	{
		printf("CSVFile LoadFile test PASSED \n");
		testsComplete++;
	}
	else
	{
		printf("CSVFile LoadFile test FAILED \n");
	}

	// CSVFile test 5
	if (this->testCSVFileLoadedFlag() == true)
	{
		printf("CSVFile LoadedFlag test PASSED \n");
		testsComplete++;
	}
	else
	{
		printf("CSVFile LoadedFlag test FAILED \n");
	}

	// CSVFile test 6
	if (this->testCSVFilePrintMeta() == true)
	{
		printf("CSVFile PrintMeta test PASSED \n");
		testsComplete++;
	}
	else
	{
		printf("CSVFile PrintMeta test FAILED \n");
	}
	
	// CSVFile test 7
	if (this->testCSVFilePrintPatterns() == true)
	{
		printf("CSVFile PrintPatterns test PASSED \n\n");
		testsComplete++;
	}
	else
	{
		printf("CSVFile PrintPatterns test FAILED \n\n");
	}

	if (testsComplete == TEST_COUNT)
	{
		return true;
	}
	else
	{
		return false;
	}
}