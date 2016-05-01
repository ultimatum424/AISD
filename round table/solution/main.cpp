#include "stdafx.h"
#include "solution.h"

int main()
{
	std::vector<int> company = ReadFile();
	int numberSolution = ChoseSolution(company);
	std::string seating = GetSolution(company, numberSolution);
	return 0;
}
