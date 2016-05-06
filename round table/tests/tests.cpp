// tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../solution/solution.h"
#include <vector>
#include <time.h>


BOOST_AUTO_TEST_SUITE(RoundTableTests)

	BOOST_AUTO_TEST_CASE(CheckForBig)
	{
		float fTimeStart = clock() / (float)CLOCKS_PER_SEC;
		std::vector<int> company = { 1000, 1000 };
		int numberSolution = ChooseSolution(company);
		std::string seating = GetSolution(company, numberSolution);
		Output(seating);
		float fTimeStop = clock() / (float)CLOCKS_PER_SEC;
		BOOST_CHECK((fTimeStop - fTimeStart) < 2);
	}

	BOOST_AUTO_TEST_CASE(CheckForNull) 
	{
		std::vector<int> company = { 0, 0 };
		float fTimeStart = clock() / (float)CLOCKS_PER_SEC;
		BOOST_CHECK_EQUAL(NO_DECISION, ChooseSolution(company));
		float fTimeStop = clock() / (float)CLOCKS_PER_SEC;
		BOOST_CHECK((fTimeStop - fTimeStart) < 2);
	}


	BOOST_AUTO_TEST_CASE(CheckForMoreBoys)
	{
		std::vector<int> company = { 41, 20 };
		float fTimeStart = clock() / (float)CLOCKS_PER_SEC;
		BOOST_CHECK_EQUAL(MORE_BOYS, ChooseSolution(company));
		float fTimeStop = clock() / (float)CLOCKS_PER_SEC;
		BOOST_CHECK((fTimeStop - fTimeStart) < 2);
	}


	BOOST_AUTO_TEST_CASE(CheckForMoreGirls)
	{
		float fTimeStart = clock() / (float)CLOCKS_PER_SEC;
		std::vector<int> company = { 51, 126 };
		BOOST_CHECK_EQUAL(MORE_GIRLS, ChooseSolution(company));
		float fTimeStop = clock() / (float)CLOCKS_PER_SEC;
		BOOST_CHECK((fTimeStop - fTimeStart) < 2);
	}

	BOOST_AUTO_TEST_CASE(CheckSolutionMoreGirl)
	{
		std::vector<int> company = { 2, 7 };
		std::string seating = "BGGBGGGGG";
		float fTimeStart = clock() / (float)CLOCKS_PER_SEC;
		BOOST_CHECK(seating == GetSolutionWhenManyGirls(company));
		float fTimeStop = clock() / (float)CLOCKS_PER_SEC;
		BOOST_CHECK((fTimeStop - fTimeStart) < 2);
	}
	BOOST_AUTO_TEST_CASE(CheckSolutionMoreBoys0)
	{
		std::vector<int> company = { 10, 4 };
		std::string seating = "BGGBGGBBBBBBBB";
		float fTimeStart = clock() / (float)CLOCKS_PER_SEC;
		BOOST_CHECK(seating == GetSolutionWhenManyBoys(company));
		float fTimeStop = clock() / (float)CLOCKS_PER_SEC;
		BOOST_CHECK((fTimeStop - fTimeStart) < 2);
	}
	
	BOOST_AUTO_TEST_CASE(CheckSolutionMoreBoys1)
	{
		std::vector<int> company = { 10, 5 };
		std::string seating = "BGGBGGBBBBBBBBG";
		float fTimeStart = clock() / (float)CLOCKS_PER_SEC;
		BOOST_CHECK(seating == GetSolutionWhenManyBoys(company));
		float fTimeStop = clock() / (float)CLOCKS_PER_SEC;
		BOOST_CHECK((fTimeStop - fTimeStart) < 2);
	}

	
BOOST_AUTO_TEST_SUITE_END()
