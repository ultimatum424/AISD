// Friday.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "solution.h"

/*
13.20 ������� 13 (5)

����������� ������ � ����, �� ������� ���������� ������� 13-�� ����� � �������� ���������
��� �� ��������� 1901-2099 �.�.
���� �� ����� INPUT.TXT. � ������������ ������ �������� ����� ������ ��������� �
�������� ����.
����� � ���� OUTPUT.TXT. ��������� ������� �����, ������� ������� ������ 13-�� �����.

������
����
1952 1954

�����
1952 JUNE
1953 FEBRUARY
1953 MARCH
1953 NOVEMBER
1954 AUGUST
*/


int main()
{
	std::pair<int, int> dates = ReadFile("input.txt");
	std::vector<std::string> listFriday13 = Couting(dates.first, dates.second);
	OutResult("output.txt", listFriday13);

	return 0;
}
   
	


