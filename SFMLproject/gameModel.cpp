#include "gameModel.h"

void gameModel::generateBoard()
{
	//generowanie planszy z zerowymi wartoœciami
	for (int i = 0; i < this->boardSize; i++) {
		vector<int> secondTab;
		this->board.push_back(secondTab);
		for (int j = 0; j < this->boardSize; j++) {
			this->board[i].push_back(0);
		}
	}

	//losowanie lokalizacji bomb i umiejscowienie ich na planszy
	for (int i = 0; i < 12; i++) {
		int x = rand() % 100;
		int y = rand() % 100;
		if (this->board[x][y] == 0) {
			this->board[x][y] = 9;
		}
	}

	//liczenie bomb obok ka¿dego pola
	for (int i = 0; i < this->boardSize; i++) {
		for (int j = 0; j < this->boardSize; j++) {
		}
	}
}

int gameModel::setBoardSize()
{
	return 0;
}
