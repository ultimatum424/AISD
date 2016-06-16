#pragma once
#include "stdafx.h"

std::pair<int, int> ReadFile(const std::string& nameFile);

std::vector<std::string> Couting(int const start, int const end);

void OutResult(const std::string& nameFile, const std::vector<std::string>& listFriday13);