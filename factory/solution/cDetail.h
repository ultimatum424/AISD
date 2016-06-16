#pragma once
#include "stdafx.h"
class cDetail
{

private:
	const static int DIMENSION = 100000; // �����������
	std::vector<bool> visit; //��������� �������
	std::vector<std::vector<int>> mass; //������ ������� ������� ������
	std::vector<int> times; // ������ ����� �������� �������
	int quantityDetails; //����� ������ �����
	long long timeCreate = 0; //����� �������� �������� ������
	int quantity = 0; //���������� ������� ������������ ��� �������� 1 ������
	std::vector<int> queue; //���� ��� �������� � ������ ������
public:
	cDetail();
	void DFS(int v);
	void Read(const std::string& fileName);
	void OutResult(const std::string& outName);
	~cDetail();
};

