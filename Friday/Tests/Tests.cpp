// Tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../Friday/solution.h"
#include <time.h>

BOOST_AUTO_TEST_SUITE(Tests)

BOOST_AUTO_TEST_CASE(test1)
	{
		float fTimeStart = clock() / (float)CLOCKS_PER_SEC;
		std::vector<std::string> listFriday13 = Couting(1952, 1954);
		float fTimeStop = clock() / (float)CLOCKS_PER_SEC;
		BOOST_CHECK(listFriday13.size() == 5);
		BOOST_CHECK((fTimeStop - fTimeStart) < 2);
	}

	BOOST_AUTO_TEST_CASE(test2)
	{
		float fTimeStart = clock() / (float)CLOCKS_PER_SEC;
		std::vector<std::string> listFriday13 = Couting(1901, 1901);
		float fTimeStop = clock() / (float)CLOCKS_PER_SEC;
		BOOST_CHECK(listFriday13.size() == 2);
		BOOST_CHECK((fTimeStop - fTimeStart) < 2);
	}

	BOOST_AUTO_TEST_CASE(test3)
	{
		float fTimeStart = clock() / (float)CLOCKS_PER_SEC;
		std::vector<std::string> listFriday13 = Couting(1902, 1902);
		float fTimeStop = clock() / (float)CLOCKS_PER_SEC;
		BOOST_CHECK(listFriday13.size() == 1);
		BOOST_CHECK((fTimeStop - fTimeStart) < 2);
	}

	BOOST_AUTO_TEST_CASE(test4)
	{
		float fTimeStart = clock() / (float)CLOCKS_PER_SEC;
		std::vector<std::string> listFriday13 = Couting(1901, 2099);
		float fTimeStop = clock() / (float)CLOCKS_PER_SEC;
		BOOST_CHECK(listFriday13.size());
		BOOST_CHECK((fTimeStop - fTimeStart) < 2);
	}

BOOST_AUTO_TEST_SUITE_END()