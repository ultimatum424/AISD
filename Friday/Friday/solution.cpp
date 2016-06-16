#include "stdafx.h"
#include "solution.h"

std::pair<int, int> ReadFile(const std::string& nameFile)
{
	std::ifstream inputFile;
	inputFile.open(nameFile);
	std::pair<int, int> dates;
	inputFile >> dates.first;
	inputFile >> dates.second;
	return dates;
}

std::vector<std::string> Couting(int const start, int const end)
{
	int day = 0;
	int month = 9;
	int k = 0;
	std::vector<int>monthDay = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	std::vector<std::string>monthName = { "", "January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November", "December" };
	std::vector<std::string> listFriday13;

	for (int i = 1901; i <= end; i++)
	{
		while (month <= 12)
		{
			day = day % 7;
			if ((day == 0) && (i >= start))
			{
				k++;
				listFriday13.push_back(monthName[month] + " " + std::to_string(i));
			}
			day = day + monthDay[month];
			if ((month == 2) && (i % 4 == 0))
			{
				day++;
			}
			month++;
		}
		month = 1;
	}
	return listFriday13;
}

void OutResult(const std::string& nameFile, const std::vector<std::string>& listFriday13)
{
	std::ofstream outputFile;
	outputFile.open(nameFile);
	std::ostream_iterator<std::string> out_it(outputFile, "\n");
	std::copy(listFriday13.begin(), listFriday13.end(), out_it);
}