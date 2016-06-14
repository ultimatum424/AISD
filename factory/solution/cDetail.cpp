#include "stdafx.h"
#include "cDetail.h"

using namespace std;
cDetail::cDetail()
{
}

void cDetail::DFS(int cunrrentVertex)
{
	visit[cunrrentVertex] = 1;
	timeCreate += times[cunrrentVertex];
	quantity++; 
	vector<int>::iterator iter = mass[cunrrentVertex].begin();
	while (iter != mass[cunrrentVertex].end())
	{
		if (visit[*iter] != 1)
			DFS(*iter);
		iter++;
	}
	queue.push_back(cunrrentVertex + 1);
}

void cDetail::Read(const string& fileName)
{
	ifstream inputFile;
	inputFile.open(fileName);
	inputFile >> quantityDetails;
	visit.resize(quantityDetails);
	mass.resize(quantityDetails);
	times.resize(quantityDetails);

	for (size_t i = 0; i < quantityDetails; ++i)
		inputFile >> times[i];
	for (size_t i = 0; i < quantityDetails; ++i)
	{
		int k;
		inputFile >> k;
		for (size_t j = 0; j < k; ++j)
		{
			int g;
			inputFile >> g;
			g--;
			mass[i].push_back(g);
		}
	}
}
void cDetail::OutResult(const string& outName)
{
	ofstream outFile;
	outFile.open(outName);
	outFile << timeCreate << " " << quantity << endl;
	std::ostream_iterator<int> out_it(outFile, " ");
	copy(queue.begin(), queue.end(), out_it);
}


cDetail::~cDetail()
{
}
