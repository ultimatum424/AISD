// tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../solution/solution.h"
#include <vector>

enum numberSolution { noDecision, moreGirls, moreBoys0, moreBoys1 };

BOOST_AUTO_TEST_SUITE(RoundTableTests)

	BOOST_AUTO_TEST_CASE(CheckForNull) 
	{
		std::vector<int> company = { 0, 0 };
		BOOST_CHECK_EQUAL(noDecision, ChoseSolution(company));
	}


	BOOST_AUTO_TEST_CASE(CheckForMoreBoys0)
	{
		std::vector<int> company = { 41, 20 };
		BOOST_CHECK_EQUAL(moreBoys0, ChoseSolution(company));
	}

	BOOST_AUTO_TEST_CASE(CheckForMoreBoys1)
	{
		std::vector<int> company = { 41, 23 };
		BOOST_CHECK_EQUAL(moreBoys1, ChoseSolution(company));
	}

	BOOST_AUTO_TEST_CASE(CheckForMoreGirls)
	{
		std::vector<int> company = { 51, 126 };
		BOOST_CHECK_EQUAL(moreGirls, ChoseSolution(company));
	}

	BOOST_AUTO_TEST_CASE(CheckSolutionMoreGirl)
	{
		std::vector<int> company = { 2, 7 };
		std::string seating = "BGGBGGGGG";
		BOOST_CHECK(seating == GetSolutionMoreGirl(company));
	}
	BOOST_AUTO_TEST_CASE(CheckSolutionMoreBoys0)
	{
		std::vector<int> company = { 10, 4 };
		std::string seating = "BGGBGGBBBBBBBB";
		BOOST_CHECK(seating == GetSolutionMoreBoys0(company));
	}
	
	BOOST_AUTO_TEST_CASE(CheckSolutionMoreBoys1)
	{
		std::vector<int> company = { 10, 5 };
		std::string seating = "BGGBGGBBBBBBBBG";
		BOOST_CHECK(seating == GetSolutionMoreBoys1(company));
	}
	
	/*
	BOOST_AUTO_TEST_CASE(CheckBadSolutionBoys)
	{
		std::vector<int> company = { 10, 0 };
		std::string bestSeating = "BBBBBBBBBB";
		BOOST_CHECK(bestSeating == GoBadSolution(company, onlyBoys));
	}

	BOOST_AUTO_TEST_CASE(CheckBadSolutionGirls)
	{
		std::vector<int> company = { 0, 10 };
		std::string bestSeating = "GGGGGGGGGG";
		BOOST_CHECK(bestSeating == GoBadSolution(company, onlyGirls));
	}
	BOOST_AUTO_TEST_CASE(CheckBadSolutionNull)
	{
		std::vector<int> company = { 0, 0 };
		std::string bestSeating = "";
		BOOST_CHECK(bestSeating == GoBadSolution(company, noDecision));
	}

	BOOST_AUTO_TEST_CASE(CheckBadSolutionmoreGirls)
	{
		std::vector<int> company = { 7, 5 };
		std::string bestSeating = "BGG";
		BOOST_CHECK(bestSeating == GoGoodSolution(company, noDecision));
	}

	BOOST_AUTO_TEST_CASE(CheckBadSolutionmoreBoys)
	{
		std::vector<int> company = { 4, 1 };
		std::string bestSeating = "";
		BOOST_CHECK(bestSeating == GoGoodSolution(company, noDecision));
	}
	*/
BOOST_AUTO_TEST_SUITE_END()
