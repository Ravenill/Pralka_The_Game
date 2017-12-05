#pragma once
#include <Windows.h>
#include "WindowEq.h"
#include "WindowEnemy.h"
#include "WindowMain.h"
#include "WindowPlayer.h"

class WindowsManager
{
private:
    WindowMain m_WindowMain;
    WindowEq m_WindowEq;
    WindowEnemy m_WindowEnemy;
    WindowPlayer m_WindowPlayer;

public:
    HINSTANCE& hInstance;
	LPSTR& lpCmdLine;
	int& nCmdShow;

public:
	WindowsManager(HINSTANCE* h_instance, LPSTR* lp_cmd_line, int* n_cmd_show);
    void Update();
};