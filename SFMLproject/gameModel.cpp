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

	//losowanie lokalizacji bomb i umiejscowienie ich na planszy | bomba = 9
	for (int i = 0; i < this->numberOfBombs; i++) {
		int x = rand() % this->boardSize;
		int y = rand() % this->boardSize;
		//cout << x << y << endl;
		if (this->board[x][y] == 0) {
			this->board[x][y] = 9;
		}
	}

	//liczenie bomb obok ka¿dego pola
	for (int i = 0; i < this->boardSize; i++) {
		for (int j = 0; j < this->boardSize; j++) {
			if (this->board[i][j] == 9) {
				int temp;
				if (i == 0 && j == 0) {
					if (this->board[i][j + 1] != 9) {
						temp = this->board[i][j + 1];
						this->board[i][j + 1] = temp + 1;
					}
					if (this->board[i + 1][j] != 9) {
						temp = this->board[i + 1][j];
						this->board[i + 1][j] = temp + 1;
					}
					if (this->board[i + 1][j + 1] != 9) {
						temp = this->board[i + 1][j + 1];
						this->board[i + 1][j + 1] = temp + 1;
					}
				}
				else if (i == 0 && j == this->boardSize-1) {
					if (this->board[i][j - 1] != 9) {
						temp = this->board[i][j - 1];
						this->board[i][j - 1] = temp + 1;
					}
					if (this->board[i + 1][j] != 9) {
						temp = this->board[i + 1][j];
						this->board[i + 1][j] = temp + 1;
					}
					if (this->board[i + 1][j - 1] != 9) {
						temp = this->board[i + 1][j - 1];
						this->board[i + 1][j - 1] = temp + 1;
					}
				}
				else if (i == this->boardSize - 1 && j == 0) {
					if (this->board[i - 1][j] != 9) {
						temp = this->board[i - 1][j];
						this->board[i - 1][j] = temp + 1;
					}
					if (this->board[i][j + 1] != 9) {
						temp = this->board[i][j + 1];
						this->board[i][j + 1] = temp + 1;
					}
					if (this->board[i - 1][j + 1] != 9) {
						temp = this->board[i - 1][j + 1];
						this->board[i - 1][j + 1] = temp + 1;
					}
				}
				else if (i == this->boardSize - 1 && j == this->boardSize - 1) {
					if (this->board[i][j - 1] != 9) {
						temp = this->board[i][j - 1];
						this->board[i][j - 1] = temp + 1;
					}
					if (this->board[i + 1][j] != 9) {
						temp = this->board[i + 1][j];
						this->board[i + 1][j] = temp + 1;
					}
					if (this->board[i + 1][j - 1] != 9) {
						temp = this->board[i + 1][j - 1];
						this->board[i + 1][j - 1] = temp + 1;
					}
				}
				else if (i == 0 && j < this->boardSize - 1 && j > 0) {
					if (this->board[i][j - 1] != 9) {
						temp = this->board[i][j - 1];
						this->board[i][j - 1] = temp + 1;
					}
					if (this->board[i][j + 1] != 9) {
						temp = this->board[i][j + 1];
						this->board[i][j + 1] = temp + 1;
					}
					if (this->board[i + 1][j - 1] != 9) {
						temp = this->board[i + 1][j - 1];
						this->board[i + 1][j - 1] = temp + 1;
					}
					if (this->board[i + 1][j] != 9) {
						temp = this->board[i + 1][j];
						this->board[i + 1][j] = temp + 1;
					}
					if (this->board[i + 1][j + 1] != 9) {
						temp = this->board[i + 1][j + 1];
						this->board[i + 1][j + 1] = temp + 1;
					}
				}
				else if (i == this->boardSize - 1 && j < this->boardSize - 1 && j > 0) {
					if (this->board[i][j - 1] != 9) {
						temp = this->board[i][j - 1];
						this->board[i][j - 1] = temp + 1;
					}
					if (this->board[i][j + 1] != 9) {
						temp = this->board[i][j + 1];
						this->board[i][j + 1] = temp + 1;
					}
					if (this->board[i - 1][j - 1] != 9) {
						temp = this->board[i - 1][j - 1];
						this->board[i - 1][j - 1] = temp + 1;
					}
					if (this->board[i - 1][j] != 9) {
						temp = this->board[i - 1][j];
						this->board[i - 1][j] = temp + 1;
					}
					if (this->board[i - 1][j + 1] != 9) {
						temp = this->board[i - 1][j + 1];
						this->board[i - 1][j + 1] = temp + 1;
					}
				}
				else if (j == 0 && i < this->boardSize - 1 && i > 0) {
					if (this->board[i+1][j] != 9) {
						temp = this->board[i+1][j];
						this->board[i+1][j] = temp + 1;
					}
					if (this->board[i-1][j] != 9) {
						temp = this->board[i-1][j];
						this->board[i-1][j] = temp + 1;
					}
					if (this->board[i + 1][j + 1] != 9) {
						temp = this->board[i + 1][j + 1];
						this->board[i + 1][j + 1] = temp + 1;
					}
					if (this->board[i - 1][j+1] != 9) {
						temp = this->board[i - 1][j+1];
						this->board[i - 1][j+1] = temp + 1;
					}
					if (this->board[i][j+1] != 9) {
						temp = this->board[i][j+1];
						this->board[i][j+1] = temp + 1;
					}
				}
				else if (j == this->boardSize - 1 && i < this->boardSize - 1 && i > 0) {
					if (this->board[i+1][j] != 9) {
						temp = this->board[i+1][j];
						this->board[i+1][j] = temp + 1;
					}
					if (this->board[i-1][j] != 9) {
						temp = this->board[i-1][j];
						this->board[i-1][j] = temp + 1;
					}
					if (this->board[i + 1][j - 1] != 9) {
						temp = this->board[i + 1][j - 1];
						this->board[i + 1][j - 1] = temp + 1;
					}
					if (this->board[i][j-1] != 9) {
						temp = this->board[i][j-1];
						this->board[i][j-1] = temp + 1;
					}
					if (this->board[i - 1][j - 1] != 9) {
						temp = this->board[i - 1][j - 1];
						this->board[i - 1][j - 1] = temp + 1;
					}
				}
				else {
					if (this->board[i - 1][j-1] != 9) {
						temp = this->board[i - 1][j-1];
						this->board[i - 1][j-1] = temp + 1;
					}
					if (this->board[i - 1][j] != 9) {
						temp = this->board[i - 1][j];
						this->board[i - 1][j] = temp + 1;
					}
					if (this->board[i - 1][j + 1] != 9) {
						temp = this->board[i - 1][j + 1];
						this->board[i - 1][j + 1] = temp + 1;
					}
					if (this->board[i][j - 1] != 9) {
						temp = this->board[i][j - 1];
						this->board[i][j - 1] = temp + 1;
					}
					if (this->board[i][j + 1] != 9) {
						temp = this->board[i][j + 1];
						this->board[i][j + 1] = temp + 1;
					}
					if (this->board[i + 1][j-1] != 9) {
						temp = this->board[i + 1][j-1];
						this->board[i + 1][j-1] = temp + 1;
					}
					if (this->board[i + 1][j] != 9) {
						temp = this->board[i + 1][j];
						this->board[i + 1][j] = temp + 1;
					}
					if (this->board[i + 1][j+1] != 9) {
						temp = this->board[i + 1][j+1];
						this->board[i + 1][j+1] = temp + 1;
					}
				}
			}
		}
	}
}

//ustawienie poziomu trufnoœci
void gameModel::setGameDifficulty(string difficulty)
{
	if (difficulty == "easy") {
		this->boardSize = 10;
		this->numberOfBombs = 14;
	}
	else if (difficulty == "medium") {
		this->boardSize = 15;
		this->numberOfBombs = 40;
	}
	else if (difficulty == "hard") {
		this->boardSize = 20;
		this->numberOfBombs = 100;
	}
}

//vector<vector<int>> gameModel::generateGrid() {
//	vector<vector<int>> grid;
//	for (int i = 0; i < this->boardSize; i++) {
//		vector<int> secondDeck;
//		grid.push_back(secondDeck);
//		for (int j = 0; j < this->boardSize; j++) {
//			grid[i].push_back(0);
//		}
//	}
//	return grid;
//}

void gameModel::addFlag()
{
	this->flaggedCells++;
}

void gameModel::subFlag()
{
	this->flaggedCells--;
}

int gameModel::getBoardSize()
{
	return this->boardSize;
}

string gameModel::getGameDifficulty()
{
	return this->gameDifficulty;
}

string gameModel::getGameStatus()
{
	return this->gameStatus;
}

vector<vector<int>> gameModel::getBoard()
{
	return this->board;
}

void gameModel::setGameStatus(string gameStatus)
{
	this->gameStatus = gameStatus;
}
