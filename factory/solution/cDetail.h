#pragma once
#include "stdafx.h"
class cDetail
{

private:
	std::vector<bool> visit;
	std::vector<std::vector<int>> mass;
	std::vector<int> times;

	const static int DIMENSION = 100000; // размерность
	//bool visit[DIMENSION]; //посещение вершины
	//int times[DIMENSION]; //массив время создания деталей
	//std::vector<int> mass[DIMENSION];//массив списков смежных вершин
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

