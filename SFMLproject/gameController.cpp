#include "gameController.h"

gameController::~gameController()
{
}


void gameController::start_menu()
{
	gameModel model;
	gameView view;
	difficulty = view.launch(600, 600);

	switch (difficulty)
	{
	case 1:
		model.setGameDifficulty("easy");
		view.fieldLeft = model.getFieldLeft();
		break;
	case 2:
		model.setGameDifficulty("medium");
		view.fieldLeft = model.getFieldLeft();
		break;
	case 3:
		model.setGameDifficulty("hard");
		view.fieldLeft = model.getFieldLeft();
		break;
	}

	model.generateBoard();
	model.generateGrid();
	model.setGameStatus(view.play(600, 600, model));

	switch (model.getGameStatus())
	{
		case 1:
			start_menu();
			break;
		case 2:
			endGameScreen * screen = new endGameScreen;
			screen->draw();
	}
}