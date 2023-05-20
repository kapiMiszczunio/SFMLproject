#include "gameController.h"
//#include "gameModel.h"

int main()
{
	gameModel model;
	gameView view;
	gameController controller(model, view);
	controller.start_menu();


}
