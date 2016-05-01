#pragma once
#include <vector>

std::vector<int> ReadFile();
int ChoseSolution(const std::vector<int>& company);

std::string GetSolutionMoreGirl(const std::vector<int>& company);
std::string GetSolutionMoreBoys0(const std::vector<int>& company);
std::string GetSolutionMoreBoys1(const std::vector<int>& company);
std::string GetSolution(const std::vector<int>& company, int number);

void SetSolution(const std::vector<int>& company, int number);