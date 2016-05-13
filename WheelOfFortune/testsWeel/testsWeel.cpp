// testsWeel.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


#include <time.h>
#include "../weelFortune/weelFortune.h"

BOOST_AUTO_TEST_SUITE(WeelOfFortune)
BOOST_AUTO_TEST_CASE(Test01)
{
	float fTimeStart = clock() / (float)CLOCKS_PER_SEC;
	stuctWeel Weel = ReadFiles("../tests/01");
	int prize = calculationsWeel(Weel);
	float fTimeStop = clock() / (float)CLOCKS_PER_SEC;
	BOOST_CHECK(prize == 404);
	BOOST_CHECK((fTimeStop - fTimeStart) < 2);
}

BOOST_AUTO_TEST_CASE(Test02)
{
	float fTimeStart = clock() / (float)CLOCKS_PER_SEC;
	stuctWeel Weel = ReadFiles("../tests/02");
	int prize = calculationsWeel(Weel);
	float fTimeStop = clock() / (float)CLOCKS_PER_SEC;
	BOOST_CHECK(prize == 581);
	BOOST_CHECK((fTimeStop - fTimeStart) < 2);
}

BOOST_AUTO_TEST_CASE(Test20)
{
	float fTimeStart = clock() / (float)CLOCKS_PER_SEC;
	stuctWeel Weel = ReadFiles("../tests/20");
	int prize = calculationsWeel(Weel);
	float fTimeStop = clock() / (float)CLOCKS_PER_SEC;
	BOOST_CHECK(prize == 471);
	BOOST_CHECK((fTimeStop - fTimeStart) < 2);
}

BOOST_AUTO_TEST_CASE(Test50)
{
	float fTimeStart = clock() / (float)CLOCKS_PER_SEC;
	stuctWeel Weel = ReadFiles("../tests/50");
	int prize = calculationsWeel(Weel);
	float fTimeStop = clock() / (float)CLOCKS_PER_SEC;
	BOOST_CHECK(prize == 992);
	BOOST_CHECK((fTimeStop - fTimeStart) < 2);
}
BOOST_AUTO_TEST_SUITE_END()
