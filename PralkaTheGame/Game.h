#pragma once
#include <Windows.h>
#include "Window.h"

class Game
{
private:
	Window m_Window;

public:
	Game(HINSTANCE& h_instance, LPSTR& lp_cmd_line, int& n_cmd_show);
	~Game();

	void MainLoop();
};