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

	/*
	* Funkcja wyœwietla lokacje pól w konsoli
	for (int i = 0; i < model.getBoardSize(); i++)
	{
		for (int j = 0; j < model.getBoardSize(); j++)
		{
			cout << model.getBoard()[i][j];
		}
		cout << endl;
	}
	*/

	model.setGameStatus(view.play(600, 600, model));
	switch (model.getGameStatus())
	{
		case 1:
			start_menu();
			break;
	}
}