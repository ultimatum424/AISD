// solution.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <time.h>
#include "cDetail.h"

using namespace std;

int main()
{
	cDetail details;
	details.Read("../testsKey/2");
	details.DFS(0);
	details.OutResult("output.txt");
	return 0;
}