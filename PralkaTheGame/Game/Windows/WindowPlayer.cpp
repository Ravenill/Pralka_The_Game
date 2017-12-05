#include "WindowPlayer.h"

void WindowPlayer::SetClassName()
{
    m_Name = L"PralkaTheGame_WindowPlayer";
}

WindowPlayer::WindowPlayer(HINSTANCE& h_instance, int& n_cmd_show, WindowMain& main_app)
: WindowParams(main_app)
{
    m_hInstance = &h_instance;
    SetClassName();
    SetMainWindow(main_app.GetWindowHandler());
    SetWindow(h_instance);
    RegisterWindow();
    CreateRegisteredWindow(h_instance, main_app.GetWindowHandler());
    ShowRegisteredWindow(n_cmd_show);
}

void WindowPlayer::SetWindow(HINSTANCE& h_instance)
{
    __super::SetWindow(h_instance);
    m_Window.lpfnWndProc = WndProcPlayer;
}

void WindowPlayer::CreateRegisteredWindow(HINSTANCE& h_instance, HWND& h_main_window)
{
    m_hWindow = CreateWindowEx(WS_EX_TOOLWINDOW                   // rozszerzony styl
                             , m_Name			    // klasa okna
                             , L"Gracz"	            // tekst na p. tytu³u
                             , WS_HELPWINDOW   // styl okna
                             , WindowParams.left         // wspó³rzêdna X
                             , WindowParams.top         // wspó³rzêdna Y
                             , WindowParams.m_WindowWidth         // szerokoœæ
                             , WindowParams.m_WindowHeight         // wysokoœæ
                             , m_MainAppWindow                  // okno nadrzêdne
                             , NULL                  // menu
                             , h_instance            // instancjs aplikacji
                             , NULL);
}

WindowPlayer::WindowPlayerParams::WindowPlayerParams(WindowMain& main_app)
{
    SCALE_X = 0.1f;
    SCALE_Y = 0.5f;

    SetWindowSize();
    left = main_app.GetWindowParams().m_X - (m_WindowWidth) - (main_app.GetWindowParams().m_WindowWidth / 2);
    top = main_app.GetWindowParams().m_Y - (main_app.GetWindowParams().m_WindowHeight / 2);
    CalculateXY();
    CalculateRB();
}

LRESULT WndProcPlayer(HWND hWindow, UINT uMsg, WPARAM wParam, LPARAM lParam)
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