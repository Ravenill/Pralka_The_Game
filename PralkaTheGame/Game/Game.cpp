#include "Game.h"

Game::Game(HINSTANCE* h_instance, LPSTR* lp_cmd_line, int* n_cmd_show)
: m_Windows(h_instance, lp_cmd_line, n_cmd_show)
{
	MessageLoop();
}

Game::~Game()
{

}

void Game::MessageLoop()
{
	MSG msg;
    msg.message = WM_NULL;

	while (msg.message != WM_QUIT)
	{
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            Update();
        }
	}
}

void Game::Update()
{
    m_Windows.Update();
}
