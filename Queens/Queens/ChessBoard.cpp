#include "stdafx.h"
#include "ChessBoard.h"


CChessBoard::CChessBoard()
{
}


CChessBoard::~CChessBoard()
{
}

void CChessBoard::ReadFile(const std::string& nameFile)
{
	std::ifstream inputFile;
	max = 0;
	inputFile.open(nameFile);
	inputFile >> m_numCell;
	m_table.resize(m_numCell * m_numCell);
	for (int i = 0; i < m_numCell; i++)
	{
		for (int j = 0; j < m_numCell; j++)
		{
			m_table[i][j] = (i + 1) * (j + 1);
		}
	}
}
void CChessBoard::ReadFile(int i)
{
	max = 0;
	m_numCell = i;
	m_table.resize(m_numCell);
	int k = 0;
	for (int i = 0; i < m_numCell; i++)
	{
		for (int j = 0; j < m_numCell; j++)
		{
			k++;
			m_table[i].push_back(k);
		}
	}
}


void CChessBoard::Arrangement()
{
	int remainder = m_numCell % 12;
	//÷¸òíûå
	for (int i = 2; i <= m_numCell; i = i + 2)
	{
		m_locInVrt.push_back(i);
	}
	if (remainder == 3 || remainder == 9)
	{
		m_locInVrt.erase(m_locInVrt.begin());
		m_locInVrt.push_back(2);
	}
	//íå÷¸òíûåû
	if (remainder == 8)
	{
		int j = 1;
		for (int i = 3; i <= m_numCell; i = i + 4)
		{
			m_locInVrt.push_back(i);
			m_locInVrt.push_back(j);
			j = j + 4;
		}
	}
	else
	{
		for (int i = 1; i <= m_numCell; i = i + 2)
		{
			m_locInVrt.push_back(i);
		}
	}
	
	if (remainder == 2)
	{
		auto it1 = std::find(m_locInVrt.begin(), m_locInVrt.end(), 1);
		auto it2 = std::find(m_locInVrt.begin(), m_locInVrt.end(), 3);
		if (*it1 == 1 || *it2 == 3)
		{
			size_t index1 = std::distance(m_locInVrt.begin(), it1);
			size_t index2 = std::distance(m_locInVrt.begin(), it2);
			m_locInVrt[index1] = 3;
			m_locInVrt[index2] = 1;
		}
		if (m_numCell >= 5)
		{
			auto it1 = std::find(m_locInVrt.begin(), m_locInVrt.end(), 5);
			if (*it1 == 5)
			{
				m_locInVrt.erase(it1);
				m_locInVrt.push_back(5);
			}
		}
	}
	if (remainder == 3 || remainder == 9)
	{
		auto it1 = std::find(m_locInVrt.begin(), m_locInVrt.end(), 1);
		if (*it1 == 1)
		{
			m_locInVrt.erase(it1);
			m_locInVrt.push_back(1);
		}
		auto it2 = std::find(m_locInVrt.begin(), m_locInVrt.end(), 3);
		if (*it2 == 3)
		{
			m_locInVrt.erase(it2);
			m_locInVrt.push_back(3);
		}
	}
}

void CChessBoard::ÑonsiderSum()
{
	for (auto& element : m_locInVrt)
	{
		element--;
	}
	for (int k = 0; k < m_numCell; k++)
	{
		int t = m_locInVrt[k];

		max += m_table[k][t];
	}
}

void CChessBoard::OutputResult(const std::string& nameFile)
{
	std::ofstream outFile;
	outFile.open(nameFile);
	outFile << max;
}

int CChessBoard::OutputResult()
{
	return max;
}
