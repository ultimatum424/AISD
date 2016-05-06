// solution.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>	
#include <fstream>
#include <vector>
#include "solution.h"


using namespace std;



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

SolutionWay ChooseSolution(const vector<int>& company) {
	if ((company[0] == 0) && (company[1] == 0))
	{
		return NO_DECISION;
	}
	else if ((company[0] * 2) <= (company[1]))
	{
		return MORE_GIRLS;
	}
	else
	{
		return MORE_BOYS;
	}
}

string GetSolutionWhenManyGirls(const vector<int>& company)
{
	string seating;
	for (size_t i = 0; i < company[0]; i++)
		seating = seating + "BGG";
	for (size_t i = 0; i < (company[1] - (company[0] * 2)); i++)
		seating = seating + "G";

	return seating;
}

string GetSolutionWhenManyBoys(const vector<int>& company)
{
	string seating;
	for (size_t i = 0; i < (company[1] / 2); i++)
		seating = seating + "BGG";
	for (size_t i = 0; i < (company[0] - (company[1] / 2)); i++)
		seating = seating + "B";
	if (company[1] % 2)
		seating = seating + "G";
	return seating;
}

string GetSolution(const vector<int>& company, int number)
{
	if (number == MORE_GIRLS)
		return GetSolutionWhenManyGirls(company);
	else if (number == MORE_BOYS)
		return GetSolutionWhenManyBoys(company);
	else
		return "";
}

void Output(const string & seating)
{
	ofstream outFile;
	outFile.open("output.txt");
	outFile << seating;
}


