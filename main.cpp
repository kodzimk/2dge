#include"GameEngine.h"
#include"GameApp.h"

int main()
{
	GameEngine* game;
	GameApp* app;

	app = nullptr;
	game = new GameEngine();

	while (game != nullptr || app !=nullptr)
	{
		if (game != nullptr)
		{
			game->update();
			game->render();
			if (game->startGame())
			{
				game->mapEditor->tileMap->savetoFile("game.txt");
				game = nullptr;
				app = new GameApp();
			}
		}
		else
		{
			app->render();
			app->update();
		}

	}

	delete game;
	delete app;
	return 0;
}