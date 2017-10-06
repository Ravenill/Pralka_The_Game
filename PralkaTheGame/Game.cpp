#include "Game.h"

Game::Game(HINSTANCE& h_instance, LPSTR& lp_cmd_line, int& n_cmd_show)
	: m_Window(h_instance, lp_cmd_line, n_cmd_show)
{
	MainLoop();
}

Game::~Game()
{

}

void Game::MainLoop()
{
	MSG msgKomunikat;
	while (GetMessage(&msgKomunikat, NULL, 0, 0))
	{
		TranslateMessage(&msgKomunikat);
		DispatchMessage(&msgKomunikat);
	}
}