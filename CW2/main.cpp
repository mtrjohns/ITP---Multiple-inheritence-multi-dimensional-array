/******************
*** Main Source ***
******************/

#include "Pattern.h"
#include "InputPattern.h"
#include "OutputPattern.h"
#include "TestHarness.h"
#include "CSVFile.h"

int main(int argc, char* argv[])
{

	TestHarness *test = new TestHarness();

	test->testInputPattern();
	test->testOutputPattern();
	test->testCSVFile();
	
	delete test;
	test = nullptr;

	return 0;

}