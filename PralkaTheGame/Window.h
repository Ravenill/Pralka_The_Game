#pragma once
#include <Windows.h>

class Window
{
public:
	WNDCLASSEX m_MainWindow;
	HWND m_hOkno;
	HINSTANCE* m_hInstance;
	LPSTR* m_lpCmdLine;
	int* m_nCmdShow;
	LPCWSTR m_Name;

public:
	Window(HINSTANCE& h_instance, LPSTR& lp_cmd_line, int& n_cmd_show);
};

LRESULT WINAPI WndProc(HWND hWindow, UINT uMsg, WPARAM wParam, LPARAM lParam);