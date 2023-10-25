#include"GameEngine.h"
#include"GameApp.h"

int main()
{
	GameEngine* game;

	game = new GameEngine();

	while (game != nullptr)
	{
		game->update();
		game->render();
	}

	return 0;
}