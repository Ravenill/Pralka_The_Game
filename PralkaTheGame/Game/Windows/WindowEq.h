#pragma once
#include "Window.h"
#include "WindowMain.h"
#include "../Player/Eq.h"

class WindowEq : public Window
{
public:
    friend LRESULT WINAPI WndProcEq(HWND hWindow, UINT uMsg, WPARAM wParam, LPARAM lParam);

private:
    HWND m_hComboBoxHead;
    HWND m_hComboBoxArmor;
    HWND m_hComboBoxWeaponOne;
    HWND m_hComboBoxBooty;

private:
    Eq m_Eq;

private:
    void SetClassName() override;
    void CreateRegisteredWindow(HINSTANCE& h_instance, HWND& h_main_window) override;
    void SetWindow(HINSTANCE& h_instance) override;
    void CreateComboBoxes();
    void AddItem();

private:
    struct WindowEqParams : public Params
    {
        WindowEqParams(WindowMain& main_app);
    } WindowParams;

public:
    WindowEq(HINSTANCE& h_instance, int& n_cmd_show, WindowMain& main_app);
    void Update(std::string item);
};