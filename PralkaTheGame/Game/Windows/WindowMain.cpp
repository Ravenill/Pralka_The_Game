#include "WindowMain.h"
#include "..\..\Backstage\Enum.h"
#include "..\..\Backstage\Blackboard.h"
#include "..\..\Backstage\Tools.h"

Blackboard g_bb;

void WindowMain::SetClassName()
{
    m_Name = L"PralkaTheGame_WindowMain";
}

WindowMain::WindowMain(HINSTANCE & h_instance, int & n_cmd_show)
: m_Scene()
{
    m_hInstance = &h_instance;
    SetClassName();
    SetWindow(h_instance);
    RegisterWindow();
    CreateRegisteredWindow(h_instance, m_hWindow);
    ShowRegisteredWindow(n_cmd_show);
    CreateButtons();
    UpdateButtons();
    UpdateDesc();
}

void WindowMain::Update()
{
    if (g_bb.Main > 0)
    {
        m_Scene.Update(g_bb.Main);
        UpdateDesc();
        UpdateButtons();
    }
}

void WindowMain::SetWindow(HINSTANCE& h_instance)
{
    __super::SetWindow(h_instance);
    m_Window.lpfnWndProc = WndProcMain;
}

void WindowMain::CreateButtons()
{
    const int WIDTH = (WindowParams.m_WindowWidth - 100) / 3;
    const int HEIGHT = (WindowParams.m_SystemHeight / 20);
    const int X = 20;
    const int Y = WindowParams.m_WindowHeight - 50 - HEIGHT;
    const int YSPACE = 25;
    
    m_hButton1 = CreateWindowEx(0, L"BUTTON", L"Pralka 1", WS_CHILD | WS_VISIBLE, X, Y, WIDTH, HEIGHT, m_hWindow, (HMENU)ID_BUTTON_1, *m_hInstance, NULL);
    m_hButton2 = CreateWindowEx(0, L"BUTTON", L"Pralka 2", WS_CHILD | WS_VISIBLE, X + YSPACE + WIDTH, Y, WIDTH, HEIGHT, m_hWindow, (HMENU)ID_BUTTON_2, *m_hInstance, NULL);
    m_hButton3 = CreateWindowEx(0, L"BUTTON", L"Pralka 3", WS_CHILD | WS_VISIBLE, X + 2*WIDTH + 2*YSPACE, Y, WIDTH, HEIGHT, m_hWindow, (HMENU)ID_BUTTON_3, *m_hInstance, NULL);
}

void WindowMain::UpdateButtons()
{
    LPCWSTR button_label[3];
    std::wstring w_str_button_lab[3];
    for (int i = 0; i < 3; i++)
    {
        std::string str_button_lab = m_Scene.GetOpt(i);
        w_str_button_lab[i] = Str2Wstr(str_button_lab);
        button_label[i] = w_str_button_lab[i].c_str();
    }
    
    SendMessage(m_hButton1, WM_SETTEXT, 0, (LPARAM)button_label[0]);
    SendMessage(m_hButton2, WM_SETTEXT, 0, (LPARAM)button_label[1]);
    SendMessage(m_hButton3, WM_SETTEXT, 0, (LPARAM)button_label[2]);

    g_bb.Main = 0;
}

void WindowMain::UpdateDesc()
{
    InvalidateRect(m_hWindow, NULL, false);

    RECT place;
    place.left = 0;
    place.right = WindowParams.m_WindowWidth;
    place.top = 0;
    place.bottom = WindowParams.m_WindowHeight - 200;

    std::wstring desc = Str2Wstr(m_Scene.GetDesc());

    //PAINTSTRUCT ps;
    HDC h_hdcwindow = GetDC(m_hWindow);
    //HDC h_hdcwindow = BeginPaint(m_hWindow, &ps);
    DrawText(h_hdcwindow, desc.c_str(), desc.length(), &place, DT_CENTER | DT_VCENTER | DT_WORDBREAK);
    //EndPaint(m_hWindow, &ps);
    ReleaseDC(m_hWindow, h_hdcwindow);
}

void WindowMain::CreateRegisteredWindow(HINSTANCE& h_instance, HWND& h_main_window)
{
    m_hWindow = CreateWindowEx(NULL                           // rozszerzony styl
                            , m_Name			             // klasa okna
                            , L"G³ówne okno"	             // tekst na p. tytu³u
                            , WS_MAINWINDOW            // styl okna
                            , WindowParams.left              // wspó³rzêdna X
                            , WindowParams.top               // wspó³rzêdna Y
                            , WindowParams.m_WindowWidth         // szerokoœæ
                            , WindowParams.m_WindowHeight         // wysokoœæ
                            , NULL                          // okno nadrzêdne
                            , NULL                          // menu
                            , h_instance                    // instancjs aplikacji
                            , NULL);
}

WindowMain::WindowMainParams::WindowMainParams()
{
    SCALE_X = 0.4f;
    SCALE_Y = 0.5f;

    SetWindowSize();
    left = (m_SystemWidth / 2) - (m_WindowWidth / 2);
    top = (m_SystemHeight / 2) - (m_WindowHeight / 2) + 50;
    CalculateXY();
    CalculateRB();
}

LRESULT WndProcMain(HWND hWindow, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CLOSE:
        if (MessageBox(hWindow, L"Na pewno chcesz uciec i udawaæ, ¿e nigdy nie mia³eœ/aœ pralki?", L"Ju¿ uciekasz?", MB_YESNO || MB_ICONQUESTION) == IDOK)
            DestroyWindow(hWindow);
        return 0;
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
        break;
    case WM_COMMAND:
        switch (wParam)
        {
        case ID_BUTTON_1:
            g_bb.Main = 1;
            break;
        case ID_BUTTON_2:
            g_bb.Main = 2;
            break;
        case ID_BUTTON_3:
            g_bb.Main = 3;
            break;
        default:
            g_bb.Main = 0;
            break;
        }
        break;
    }

    return DefWindowProc(hWindow, uMsg, wParam, lParam);
}