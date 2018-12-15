#include "winterm.h"

#include <Windows.h>

void SetConsoleColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
