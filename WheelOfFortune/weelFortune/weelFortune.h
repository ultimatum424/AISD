#pragma once

#include "stdafx.h"
struct stuctWeel {
	std::vector<int> prize;
	int quantyPrize;
	int sector;
	int maxForce;
	int minForce;
};

stuctWeel ReadFiles(const std::string& nameFile);
int calculationsWeel(stuctWeel& Weel);