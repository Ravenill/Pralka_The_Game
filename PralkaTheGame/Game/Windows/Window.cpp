#include "Window.h"
/*
Window::Window(HINSTANCE& h_instance, int& n_cmd_show)
{
    SetClassName();
    SetWindow(h_instance);
    RegisterWindow();
    CreateRegisteredWindow(h_instance);
    ShowRegisteredWindow(n_cmd_show);
}
*/

Window::Window()
: m_MainAppWindow(NULL)
, m_hWindow(NULL)
{

}

void Window::SetMainWindow(HWND & h_main_app)
{
    m_MainAppWindow = h_main_app;
}

void Window::SetWindow(HINSTANCE& h_instance)
{
    m_Window.cbSize = sizeof(WNDCLASSEX);
    m_Window.style = 0;
    m_Window.lpfnWndProc = WndProc;
    m_Window.cbClsExtra = 0;
    m_Window.cbWndExtra = 0;
    m_Window.hInstance = h_instance;
    m_Window.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    m_Window.hCursor = LoadCursor(NULL, IDC_ARROW);
    m_Window.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    m_Window.lpszMenuName = NULL;
    m_Window.lpszClassName = m_Name;
    m_Window.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
}

void Window::RegisterWindow()
{
    RegisterClassEx(&m_Window);
}

void Window::CreateRegisteredWindow(HINSTANCE& h_instance, HWND& h_main_window)
{
    m_hWindow = CreateWindowEx(NULL                  // rozszerzony styl
                            , m_Name			    // klasa okna
                            , L"G³ówne okno"	    // tekst na p. tytu³u
                            , WS_OVERLAPPEDWINDOW   // styl okna
                            , CW_USEDEFAULT         // wspó³rzêdna X
                            , CW_USEDEFAULT         // wspó³rzêdna Y
                            , CW_USEDEFAULT         // szerokoœæ
                            , CW_USEDEFAULT         // wysokoœæ
                            , NULL                  // okno nadrzêdne
                            , NULL                  // menu
                            , h_instance            // instancjs aplikacji
                            , NULL);
}

void Window::ShowRegisteredWindow(int& n_cmd_show)
{
    ShowWindow(m_hWindow, n_cmd_show);
}

HWND& Window::GetWindowHandler()
{
    return m_hWindow;
}

Window::Params::Params()
: SCALE_X(0.0f)
, SCALE_Y(0.0f)
, m_WindowHeight(0.0f)
, m_WindowWidth(0.0f)
, m_X(0.0f)
, m_Y(0.0f)
{
    
}

void Window::Params::SetWindowSize()
{
    m_WindowWidth = SCALE_X * m_SystemWidth;
    m_WindowHeight = SCALE_Y * m_SystemHeight;
}

void Window::Params::CalculateXY()
{
    m_X = left + m_WindowWidth / 2;
    m_Y = top + m_WindowHeight / 2;
}

void Window::Params::CalculateRB()
{
    right = left + m_WindowWidth;
    bottom = top + m_WindowHeight;
}

LRESULT WndProc(HWND hWindow, UINT uMsg, WPARAM wParam, LPARAM lParam)
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