#pragma once
#include "Window.h"
#include "../Parser/Scene.h"

class WindowMain : public Window
{
public:
    friend LRESULT WINAPI WndProcMain(HWND hWindow, UINT uMsg, WPARAM wParam, LPARAM lParam);

private:
    void SetClassName() override;
    void CreateRegisteredWindow(HINSTANCE& h_instance, HWND& h_main_window) override;
    void SetWindow(HINSTANCE& h_instance) override;
    void CreateButtons();
    void UpdateButtons();
    void UpdateDesc();

private:
    HWND m_hButton1;
    HWND m_hButton2;
    HWND m_hButton3;

private:
    Scene m_Scene;

private:
    struct WindowMainParams : public Params
    {
        WindowMainParams();
    } WindowParams;

public:
    WindowMain(HINSTANCE& h_instance, int& n_cmd_show);

    WindowMainParams GetWindowParams() const { return WindowParams; }
    Scene GetScene() const { return m_Scene; }
    void Update();
};