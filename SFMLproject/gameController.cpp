#include "gameController.h"

gameController::~gameController()
{
}


void gameController::start_menu()
{
	gameModel model;
	gameView view;

	difficulty = view.launch(600, 600);
	model.setGameDifficulty(difficulty);
	view.fieldLeft = model.getFieldLeft();

	model.generateBoard();
	model.generateGrid();
	model.setGameStatus(view.play(600, 600, model));

	switch (model.getGameStatus())
	{
		case tryAgain:
			start_menu();
			break;
		case end:
			endGameScreen * screen = new endGameScreen;
			screen->draw(view.curr_time, model.getGameDifficulty());
			delete(screen);

	}
}