// test.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../solution/stdafx.h"
#include "../solution/cDetail.h"
#include <time.h>

struct FileNameStruct
{
	std::string inputFileName;
	std::string outFileName;
	std::string answerFileName;
};

FileNameStruct SetNameFiles(int numberTest)
{
	FileNameStruct fileNames;
	std::ostringstream t;
	t << numberTest;
	fileNames.inputFileName = "..\\testsKey\\" + t.str();
	fileNames.outFileName = "..\\testsKey\\" + t.str() + ".t";
	fileNames.answerFileName = "..\\testsKey\\" + t.str() + ".a";
	return fileNames;
}

bool IsFilesEqual(std::string const& fileName1, std::string const& fileName2)
{
	auto command = "fc " + fileName1 + " " + fileName2;
	return !system(command.c_str());
}


bool RunTest(int numberTest)
{
	cDetail m_Ddtail;
	FileNameStruct fileNames = SetNameFiles(numberTest);
	float fTimeStart = clock() / (float)CLOCKS_PER_SEC;
	m_Ddtail.Read(fileNames.inputFileName);
	m_Ddtail.DFS(0);
	m_Ddtail.OutResult(fileNames.outFileName);
	float fTimeStop = clock() / (float)CLOCKS_PER_SEC;
	if ((fTimeStop - fTimeStart) < 2)
	{
		return IsFilesEqual(fileNames.outFileName, fileNames.answerFileName);
	}
	else
	{
		return false;
	}
}



BOOST_AUTO_TEST_SUITE(Tests)

	BOOST_AUTO_TEST_CASE(test1)
	{
		for (int i = 2; i <= 25; i++)
		{
			BOOST_CHECK(RunTest(i));
		}
	}

BOOST_AUTO_TEST_SUITE_END()