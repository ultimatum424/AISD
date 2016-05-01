// solution.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>	
#include <fstream>
#include <vector>


using namespace std;

enum numberSolution{noDecision, moreGirls, moreBoys0, moreBoys1};


vector<int> ReadFile() {
	vector<int> company(2, 0);
	std::ifstream inputFile;
	inputFile.open("input.txt");
	int quantityGirls = 0;
	int quantityBoys = 0;
	inputFile >> quantityBoys;
	inputFile >> quantityGirls;
	
	company[0] = quantityBoys;
	company[1] = quantityGirls;
	return company;
}

int ChoseSolution(const vector<int>& company) {
	if ((company[0] == 0) && (company[1] == 0))
	{
		return noDecision;
	}
	else if ((company[0] * 2) <= (company[1]))
	{
		return moreGirls;
	}
	else if ((company[0] * 2) > (company[1]))
	{
		if (company[1] % 2 == 0)
		{
			return moreBoys0;
		}
		else
		{
			return moreBoys1;
		}
	}
}

string GetSolutionMoreGirl(const vector<int>& company)
{
	string seating;
	for (size_t i = 0; i < company[0]; i++)
		seating = seating + "BGG";
	for (size_t i = 0; i < (company[1] - (company[0] * 2)); i++)
		seating = seating + "G";

	return seating;
}

string GetSolutionMoreBoys0(const vector<int>& company)
{
	string seating;
	for (size_t i = 0; i < (company[1] / 2); i++)
		seating = seating + "BGG";
	for (size_t i = 0; i < (company[0] - (company[1] / 2)); i++)
		seating = seating + "B";
	return seating;
}

string GetSolutionMoreBoys1(const vector<int>& company)
{
	string seating;
	for (size_t i = 0; i < (company[1] / 2); i++)
		seating = seating + "BGG";
	for (size_t i = 0; i < (company[0] - (company[1] / 2)); i++)
		seating = seating + "B";
	seating = seating + "G";
	return seating;
}

string GetSolution(const vector<int>& company, int number)
{
	if (number == noDecision)
		return "";
	else if (number == moreGirls)
		return GetSolutionMoreGirl(company);
	else if (number == moreBoys0)
		return GetSolutionMoreBoys0(company);
	else if (number == moreBoys1)
		return GetSolutionMoreBoys1(company);
}


