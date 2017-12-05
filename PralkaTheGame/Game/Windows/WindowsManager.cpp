#include "WindowsManager.h"
#include <map>

WindowsManager::WindowsManager(HINSTANCE* h_instance, LPSTR* lp_cmd_line, int* n_cmd_show)
: hInstance(*h_instance)
, lpCmdLine(*lp_cmd_line)
, nCmdShow(*n_cmd_show)
, m_WindowMain(*h_instance, *n_cmd_show)
, m_WindowEnemy(*h_instance, *n_cmd_show, m_WindowMain)
, m_WindowEq(*h_instance, *n_cmd_show, m_WindowMain)
, m_WindowPlayer(*h_instance, *n_cmd_show, m_WindowMain)
{
    
}

void WindowsManager::Update()
{
    m_WindowMain.Update();
    m_WindowEq.Update(m_WindowMain.GetScene().GetItem());
}