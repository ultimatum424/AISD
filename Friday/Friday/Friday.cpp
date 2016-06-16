// Friday.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "solution.h"

/*
13.20 Пятница 13 (5)

Перечислить месяца и годы, на которые приходится пятница 13-го числа в заданном диапазоне
лет из интервала 1901-2099 г.г.
Ввод из файла INPUT.TXT. В единственной строке задаются через пробел начальный и
конечный годы.
Вывод в файл OUTPUT.TXT. Выводится столько строк, сколько найдено пятниц 13-го числа.

Пример
Ввод
1952 1954

Вывод
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
   
	


