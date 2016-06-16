#pragma once
#include "stdafx.h"
class cDetail
{

private:
	const static int DIMENSION = 100000; // размерность
	std::vector<bool> visit; //посещение вершины
	std::vector<std::vector<int>> mass; //массив списков смежных вершин
	std::vector<int> times; // массив время создания деталей
	int quantityDetails; //число вершин графа
	long long timeCreate = 0; //время создания итоговой детали
	int quantity = 0; //количество деталей использовных для создания 1 детали
	std::vector<int> queue; //стек для хранения и вывода вершин
public:
	cDetail();
	void DFS(int v);
	void Read(const std::string& fileName);
	void OutResult(const std::string& outName);
	~cDetail();
};

