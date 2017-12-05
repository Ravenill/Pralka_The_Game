#pragma once
#include <Windows.h>

#define WS_MAINWINDOW (WS_OVERLAPPED | WS_MINIMIZEBOX | WS_CAPTION | WS_BORDER | WS_SYSMENU)
#define WS_HELPWINDOW (WS_MINIMIZEBOX | WS_CAPTION | WS_BORDER)

class Window
{
protected:
    LPCWSTR m_Name;
    WNDCLASSEX m_Window;
    HWND m_hWindow;
    HINSTANCE* m_hInstance;

protected:
    struct Params : public RECT
    {
        const float m_SystemWidth = static_cast<float>(GetSystemMetrics(SM_CXSCREEN));
        const float m_SystemHeight = static_cast<float>(GetSystemMetrics(SM_CYSCREEN));

        float m_WindowWidth;
        float m_WindowHeight;
        float m_X;
        float m_Y;

        float SCALE_X;
        float SCALE_Y;

        Params();
        void SetWindowSize();
        void CalculateXY();
        void CalculateRB();
    };

protected:
    HWND m_MainAppWindow;

protected:
    virtual void SetClassName() = 0;
    virtual void SetMainWindow(HWND& h_main_app);
    virtual void SetWindow(HINSTANCE& h_instance);
    virtual void RegisterWindow();
    virtual void CreateRegisteredWindow(HINSTANCE& h_instance, HWND& h_main_window);
    virtual void ShowRegisteredWindow(int& n_cmd_show);

public:
    Window();
    //Window(HINSTANCE& h_instance, int& n_cmd_show);

public:
    virtual HWND& GetWindowHandler();
};

LRESULT WINAPI WndProc(HWND hWindow, UINT uMsg, WPARAM wParam, LPARAM lParam);