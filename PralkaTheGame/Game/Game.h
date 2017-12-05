#pragma once
#include <Windows.h>
#include "Windows/WindowsManager.h"

class Game
{
private:
	WindowsManager m_Windows;

public:
	Game(HINSTANCE* h_instance, LPSTR* lp_cmd_line, int* n_cmd_show);
	~Game();

	void MessageLoop();
    void Update();
};