// tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <time.h>
#include "../weelFortune/weelFortune.h"

BOOST_AUTO_TEST_SUITE(WeelOfFortune)
	BOOST_AUTO_TEST_CASE(CheckForBig)
	{
		float fTimeStart = clock() / (float)CLOCKS_PER_SEC;
		stuctWeel Weel = ReadFiles("../tests/01");
		auto prize = calculationsWeel(Weel);
		float fTimeStop = clock() / (float)CLOCKS_PER_SEC;
		BOOST_CHECK(prize == 404);
		BOOST_CHECK((fTimeStop - fTimeStart) < 2);
	}

BOOST_AUTO_TEST_SUITE_END()