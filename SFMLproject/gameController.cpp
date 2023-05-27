#include "gameController.h"

gameController::~gameController()
{
}

gameController::gameController(/*gameModel& model, gameView& view) : model(model), view(view*/)
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
		break;
	case 3:
		model.setGameDifficulty("hard");
		break;
	}
	model.generateBoard();
	model.generateGrid();
	/*for (int i = 0; i < model.getBoardSize(); i++)
	{
		for (int j = 0; j < model.getBoardSize(); j++)
		{
			cout << model.getBoard()[i][j];
		}
		cout << endl;
	}*/
	view.play(600, 600, model);
	view.gameOver();
}