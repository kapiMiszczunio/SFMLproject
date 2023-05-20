#include "gameController.h"

gameController::gameController(gameModel& model, gameView& view) : model(model), view(view) 
{
}

void gameController::start_menu()
{
	view.launch(600, 600);
}



