#include "WindowEq.h"
#include "..\..\Backstage\Tools.h"

void WindowEq::SetClassName()
{
    m_Name = L"PralkaTheGame_WindowEq";
}

WindowEq::WindowEq(HINSTANCE & h_instance, int & n_cmd_show, WindowMain& main_app)
: WindowParams(main_app)
{
    m_hInstance = &h_instance;
    SetClassName();
    SetMainWindow(main_app.GetWindowHandler());
    SetWindow(h_instance);
    RegisterWindow();
    CreateRegisteredWindow(h_instance, main_app.GetWindowHandler());
    ShowRegisteredWindow(n_cmd_show);
    CreateComboBoxes();
}

void WindowEq::Update(std::string item)
{
    m_Eq.AddItem(item);

    std::wstring wstr_item = Str2Wstr(item);
    switch (m_Eq.GetInfo().WhereEquip)
    {
    case On::HEAD:
        SendMessage(m_hComboBoxHead, CB_ADDSTRING, NULL, (LPARAM)wstr_item.c_str());
        break;
    case On::BODY:
        SendMessage(m_hComboBoxArmor, CB_ADDSTRING, NULL, (LPARAM)wstr_item.c_str());
        break;
    case On::LEGS:
        SendMessage(m_hComboBoxBooty, CB_ADDSTRING, NULL, (LPARAM)wstr_item.c_str());
        break;
    case On::HAND:
        SendMessage(m_hComboBoxWeaponOne, CB_ADDSTRING, NULL, (LPARAM)wstr_item.c_str());
        break;
    default:
        break;
    }
}

void WindowEq::SetWindow(HINSTANCE& h_instance)
{
    __super::SetWindow(h_instance);
    m_Window.lpfnWndProc = WndProc;
}

void WindowEq::CreateComboBoxes()
{
    const int WIDTH = WindowParams.right - WindowParams.left - 30;
    const int HEIGHT = 20;
    const int X = 10;
    const int Y = 30;
    const int SPACE = 10;
    
    m_hComboBoxArmor = CreateWindowEx(WS_EX_CLIENTEDGE, L"COMBOBOX", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | CBS_DROPDOWN, X, Y, WIDTH, HEIGHT, m_hWindow, NULL, *m_hInstance, NULL);
    m_hComboBoxBooty = CreateWindowEx(WS_EX_CLIENTEDGE, L"COMBOBOX", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | CBS_DROPDOWN, X, Y + HEIGHT + SPACE, WIDTH, HEIGHT, m_hWindow, NULL, *m_hInstance, NULL);
    m_hComboBoxHead = CreateWindowEx(WS_EX_CLIENTEDGE, L"COMBOBOX", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | CBS_DROPDOWN, X, Y + (HEIGHT*2) + SPACE*2, WIDTH, HEIGHT, m_hWindow, NULL, *m_hInstance, NULL);
    m_hComboBoxWeaponOne = CreateWindowEx(WS_EX_CLIENTEDGE, L"COMBOBOX", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | CBS_DROPDOWN, X, Y + (HEIGHT*3) + SPACE*3, WIDTH, HEIGHT, m_hWindow, NULL, *m_hInstance, NULL);
}

void WindowEq::CreateRegisteredWindow(HINSTANCE& h_instance, HWND& h_main_window)
{
    m_hWindow = CreateWindowEx(WS_EX_TOOLWINDOW                   // rozszerzony styl
                             , m_Name			     // klasa okna
                             , L"Ekwipunek"	         // tekst na p. tytu³u
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

WindowEq::WindowEqParams::WindowEqParams(WindowMain& main_app)
{
    SCALE_X = 0.1f;
    SCALE_Y = 0.5f;

    SetWindowSize();
    left = main_app.GetWindowParams().m_X + (main_app.GetWindowParams().m_WindowWidth / 2);
    top = main_app.GetWindowParams().m_Y - (main_app.GetWindowParams().m_WindowHeight / 2);
    CalculateXY();
    CalculateRB();
}

LRESULT WndProcEq(HWND hWindow, UINT uMsg, WPARAM wParam, LPARAM lParam)
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