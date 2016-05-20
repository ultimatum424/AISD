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

int calculationsWeel(stuctWeel& Wheel)
{
	int maxAmountSectors = Wheel.maxForce / Wheel.sector;
	int minAmountSectors = Wheel.minForce / Wheel.sector;

	if (Wheel.maxForce % Wheel.sector == 0)
		maxAmountSectors--;
	if (Wheel.minForce % Wheel.sector == 0)
		minAmountSectors--;

	int start = (minAmountSectors % Wheel.quantyPrize);
	int scatter = (maxAmountSectors) - (minAmountSectors);

	if (scatter >= (Wheel.quantyPrize - 1))
	{
		auto result = max_element(Wheel.prize.begin(), Wheel.prize.end());
		return *result;
	}
	else
	{ 
		vector<int> reversPrize;
		reversPrize.push_back(Wheel.prize[0]);
		for (size_t i = Wheel.prize.size() - 1; i > 1; i--)
		{
			reversPrize.push_back(Wheel.prize[i]);
		}
		auto maxPrize1 = max_element((Wheel.prize.begin() + start), (Wheel.prize.begin() + (start + scatter)));
		auto maxPrize2 = max_element((reversPrize.begin() + start), (reversPrize.begin() + (start + scatter)));
		return  max(*maxPrize1, *maxPrize2);
	}
	
}
