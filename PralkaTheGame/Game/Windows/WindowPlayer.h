#pragma once
#include "Window.h"
#include "WindowMain.h"

class WindowPlayer : public Window
{
public:
    friend LRESULT WINAPI WndProcPlayer(HWND hWindow, UINT uMsg, WPARAM wParam, LPARAM lParam);

private:
    void SetClassName() override;
    void CreateRegisteredWindow(HINSTANCE& h_instance, HWND& h_main_window) override;
    void SetWindow(HINSTANCE& h_instance) override;

private:
    struct WindowPlayerParams : public Params
    {
        WindowPlayerParams(WindowMain& main_app);
    } WindowParams;

public:
    WindowPlayer(HINSTANCE& h_instance, int& n_cmd_show, WindowMain& main_app);
};