#pragma once
#include "OOP_Menu.h"
#include "Laba4.h"

class Init
{
private:
	Menu lab4;
public:

	Init()
	{
		lab4.AddMenuItem("������ 1, 8 ���i���: ", Zadacha1_1);
		lab4.AddMenuItem("������ 1, 8 ���i���: ", Zadacha1_2);
	}
	void Show_Lab()
	{
		lab4.ShowMenu();
	}
};