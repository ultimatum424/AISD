// weelFortune.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "weelFortune.h"


using namespace std;

stuctWeel ReadFiles(const std::string& nameFile)
{
	stuctWeel Weel;
	ifstream inputFile;
	inputFile.open(nameFile);
	vector<int> prize;
	int a;
	inputFile >> Weel.quantyPrize;
	for (size_t i = 0; i < Weel.quantyPrize; i++)
	{
		inputFile >> a;
		Weel.prize.push_back(a);
	}
	inputFile >> Weel.minForce;
	inputFile >> Weel.maxForce;
	inputFile >> Weel.sector;
	return Weel;
}

int calculationsWeel(stuctWeel& Weel)
{
	int maxAmountSectors = Weel.maxForce / Weel.sector;
	int minAmountSectors = Weel.minForce / Weel.sector;

	if (Weel.maxForce % Weel.sector == 0)
		maxAmountSectors--;
	if (Weel.minForce % Weel.sector == 0)
		minAmountSectors--;

	int start = (minAmountSectors % Weel.quantyPrize);
	int scatter = (maxAmountSectors) - (minAmountSectors);

	if (scatter >= (Weel.quantyPrize - 1))
	{
		auto result = max_element(Weel.prize.begin(), Weel.prize.end());
		return *result;
	}
	else
	{ 
		vector<int> reversPrize;
		reversPrize.push_back(Weel.prize[0]);
		for (size_t i = Weel.prize.size() - 1; i > 1; i--)
		{
			reversPrize.push_back(Weel.prize[i]);
		}
		auto maxPrize1 = max_element((Weel.prize.begin() + start), (Weel.prize.begin() + (start + scatter)));
		auto maxPrize2 = max_element((reversPrize.begin() + start), (reversPrize.begin() + (start + scatter)));
		return  max(*maxPrize1, *maxPrize2);
	}
	
}
