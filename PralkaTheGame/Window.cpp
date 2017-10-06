#include "Window.h"

Window::Window(HINSTANCE& h_instance, LPSTR& lp_cmd_line, int& n_cmd_show) : m_hInstance(&h_instance), m_lpCmdLine(&lp_cmd_line), m_nCmdShow(&n_cmd_show)
{
	m_Name = L"PralkaTheGame_v2";

	m_MainWindow.cbSize = sizeof(WNDCLASSEX);
	m_MainWindow.style = 0;
	m_MainWindow.lpfnWndProc = WndProc;
	m_MainWindow.cbClsExtra = 0;
	m_MainWindow.cbWndExtra = 0;
	m_MainWindow.hInstance = h_instance;
	m_MainWindow.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	m_MainWindow.hCursor = LoadCursor(NULL, IDC_ARROW);
	m_MainWindow.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	m_MainWindow.lpszMenuName = NULL;
	m_MainWindow.lpszClassName = m_Name;
	m_MainWindow.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&m_MainWindow);

	m_hOkno = CreateWindowEx(NULL                  // rozszerzony styl
						  	,m_Name				   // klasa okna
						 	,L"G³ówne okno"		   // tekst na p. tytu³u
							,WS_OVERLAPPEDWINDOW   // styl okna
							,CW_USEDEFAULT         // wspó³rzêdna X
							,CW_USEDEFAULT         // wspó³rzêdna Y
							,CW_USEDEFAULT         // szerokoœæ
							,CW_USEDEFAULT         // wysokoœæ
							,NULL                  // okno nadrzêdne
							,NULL                  // menu
							,h_instance            // instancjs aplikacji
							,NULL);

	ShowWindow(m_hOkno, *(m_nCmdShow));
}

LRESULT CALLBACK WndProc(HWND hWindow, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
		break;
	}

	return DefWindowProc(hWindow, uMsg, wParam, lParam);
}
