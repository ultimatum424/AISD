
#include "stdafx.h"
#include "weelFortune.h"
int main()
{
	//stuctWeel Weel;
	stuctWeel Weel = ReadFiles("../tests/1/03");
	auto prize = calculationsWeel(Weel);
	std::cout << "You win: " << prize << std::endl;
	return 0;
}

