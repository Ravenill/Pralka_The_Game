#pragma once
#include "Window.h"
#include "WindowMain.h"

class WindowEnemy : public Window
{
public:
    friend LRESULT WINAPI WndProcEnemy(HWND hWindow, UINT uMsg, WPARAM wParam, LPARAM lParam);

private:
    void SetClassName() override;
    void CreateRegisteredWindow(HINSTANCE& h_instance, HWND& h_main_window) override;
    void SetWindow(HINSTANCE& h_instance) override;

private:
    struct WindowEnemyParams : public Params
    {
        WindowEnemyParams(WindowMain& main_app);
    } WindowParams;

public:
    WindowEnemy(HINSTANCE& h_instance, int& n_cmd_show, WindowMain& main_app);
};