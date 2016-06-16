#pragma once
#include "stdafx.h"
class CChessBoard
{
public:
	CChessBoard();
	~CChessBoard();
	void ReadFile(int i);
	void ReadFile(const std::string& nameFile);
	void Arrangement();
	void ÑonsiderSum();
	void OutputResult(const std::string& nameFile);
	int OutputResult();

private:
	std::vector<int> m_locInVrt;
	std::vector<std::vector<int>> m_table;
	int max;
	int m_numCell;
};

