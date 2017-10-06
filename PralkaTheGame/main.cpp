#include <Windows.h>
#include "Game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Game game(hInstance, lpCmdLine, nCmdShow);
	return 0;
}