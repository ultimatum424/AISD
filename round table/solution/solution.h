#pragma once
#include <vector>

enum SolutionWay
{
	NO_DECISION,
	MORE_GIRLS,
	MORE_BOYS
};


std::vector<int> ReadFile();
SolutionWay ChooseSolution(const std::vector<int>& company);

std::string GetSolutionWhenManyGirls(const std::vector<int>& company);
std::string GetSolutionWhenManyBoys(const std::vector<int>& company);
std::string GetSolution(const std::vector<int>& company, int number);

void SetSolution(const std::vector<int>& company, int number);

void Output(const std::string & seating);