// Tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../Queens/ChessBoard.h"
#include <time.h>



int RunTest(const int dimension)
{
	CChessBoard chessBoard;
	chessBoard.ReadFile(dimension);
	chessBoard.Arrangement();
	chessBoard.СonsiderSum();
	return chessBoard.OutputResult();
}



BOOST_AUTO_TEST_SUITE(Tests)
	BOOST_AUTO_TEST_CASE(test1)
	{
		float fTimeStart = clock() / (float)CLOCKS_PER_SEC;
		BOOST_CHECK(RunTest(4) == 34);
		float fTimeStop = clock() / (float)CLOCKS_PER_SEC;
		BOOST_CHECK(fTimeStop - fTimeStart <= 2);
	}

	BOOST_AUTO_TEST_CASE(test2)
	{
		float fTimeStart = clock() / (float)CLOCKS_PER_SEC;
		BOOST_CHECK(RunTest(5) == 65);
		float fTimeStop = clock() / (float)CLOCKS_PER_SEC;
		BOOST_CHECK(fTimeStop - fTimeStart <= 2);
	}

	BOOST_AUTO_TEST_CASE(test3)
	{
		float fTimeStart = clock() / (float)CLOCKS_PER_SEC;
		BOOST_CHECK(RunTest(40) == 32020);
		float fTimeStop = clock() / (float)CLOCKS_PER_SEC;
		BOOST_CHECK(fTimeStop - fTimeStart <= 2);
	}

BOOST_AUTO_TEST_SUITE_END()