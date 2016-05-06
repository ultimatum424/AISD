#include "stdafx.h"
#include "solution.h"

int main()
{
	std::vector<int> company = ReadFile();
	int numberSolution = ChooseSolution(company);
	std::string seating = GetSolution(company, numberSolution);
	Output(seating);
	return 0;
}
