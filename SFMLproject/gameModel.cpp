#include "gameModel.h"
#include <fstream>
#include <iostream>
#include <string>


gameModel::~gameModel()
{
}

void gameModel::updateRanking(std::string time)
{
	std::fstream score;
	switch (gameDifficulty)
	{
	case 1:
		score.open("../Score/easy.txt");
		difficult = "easy.txt";
		break;
	case 2:
		score.open("../Score/medium.txt");
		difficult = "medium.txt";
		break;
	case 3:
		score.open("../Score/hard.txt");
		difficult = "hard.txt";
		break;
	}
	replace = "";
	int a = 0;
	if (score.is_open())
	{
		std::string line;

		int b = 0;
		while (getline(score, line))
		{
			scoree[b] = line;
			if (std::stof(time) < std::stof(line) && a == 0)
			{
				scoree[b] = time;
				a = 1;
			}
			b++;
		}

	}
	score.close();
	std::ofstream file("../Score/"+difficult);
	for (int i = 0; i < 5; i++)
	{
		file << scoree[i] << std::endl;
	}
	
}

void gameModel::generateBoard()
{
	//generates raw grid of the board with default values
	for (int i = 0; i < this->boardSize; i++) {
		std::vector<int> secondTab;
		this->board.push_back(secondTab);
		for (int j = 0; j < this->boardSize; j++) {
			this->board[i].push_back(0);
		}
	}

	//gets randomly bomb positions
	seed = time(0);
	srand(seed);
	for (int i = 0; i < this->numberOfBombs; i++) {
		int x = rand() % this->boardSize;
		int y = rand() % this->boardSize;
		if (this->board[x][y] == 0) {
			this->board[x][y] = 9;
		}
	}

	//calculating number of bombs nearby every field
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
				else if (i == 0 && j == this->boardSize - 1) {
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
					if (this->board[i + 1][j] != 9) {
						temp = this->board[i + 1][j];
						this->board[i + 1][j] = temp + 1;
					}
					if (this->board[i - 1][j] != 9) {
						temp = this->board[i - 1][j];
						this->board[i - 1][j] = temp + 1;
					}
					if (this->board[i + 1][j + 1] != 9) {
						temp = this->board[i + 1][j + 1];
						this->board[i + 1][j + 1] = temp + 1;
					}
					if (this->board[i - 1][j + 1] != 9) {
						temp = this->board[i - 1][j + 1];
						this->board[i - 1][j + 1] = temp + 1;
					}
					if (this->board[i][j + 1] != 9) {
						temp = this->board[i][j + 1];
						this->board[i][j + 1] = temp + 1;
					}
				}
				else if (j == this->boardSize - 1 && i < this->boardSize - 1 && i > 0) {
					if (this->board[i + 1][j] != 9) {
						temp = this->board[i + 1][j];
						this->board[i + 1][j] = temp + 1;
					}
					if (this->board[i - 1][j] != 9) {
						temp = this->board[i - 1][j];
						this->board[i - 1][j] = temp + 1;
					}
					if (this->board[i + 1][j - 1] != 9) {
						temp = this->board[i + 1][j - 1];
						this->board[i + 1][j - 1] = temp + 1;
					}
					if (this->board[i][j - 1] != 9) {
						temp = this->board[i][j - 1];
						this->board[i][j - 1] = temp + 1;
					}
					if (this->board[i - 1][j - 1] != 9) {
						temp = this->board[i - 1][j - 1];
						this->board[i - 1][j - 1] = temp + 1;
					}
				}
				else {
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
			}
		}
	}
}

void gameModel::setGameDifficulty(gameModel::difficulty difficulty)
{
	if (difficulty == easy) {
		this->boardSize = 10;
		this->numberOfBombs = 14;
		this->fieldLeft = 100;
		this->gameDifficulty = easy;
	}
	else if (difficulty == medium) {
		this->boardSize = 15;
		this->numberOfBombs = 40;
		this->fieldLeft = 225;
		this->gameDifficulty = medium;
	}
	else if (difficulty == hard) {
		this->boardSize = 20;
		this->numberOfBombs = 100;
		this->fieldLeft = 400;
		this->gameDifficulty = hard;
	}
}

void gameModel::generateGrid() {
	for (int i = 0; i < this->boardSize; i++) {
		std::vector<int> secondDeck;
		grid.push_back(secondDeck);
		for (int j = 0; j < this->boardSize; j++) {
			grid[i].push_back(10);
		}
	}
}

std::vector<std::vector<int>> gameModel::getGrid()
{
	return this->grid;
}

int gameModel::getBoardSize()
{
	return this->boardSize;
}

int gameModel::getFieldLeft()
{
	return this->fieldLeft;
}

int gameModel::getGameDifficulty()
{
	return this->gameDifficulty;
}

int gameModel::getGameStatus()
{
	return this->gameStatus;
}

std::vector<std::vector<int>> gameModel::getBoard()
{
	return this->board;
}

void gameModel::setGameStatus(int gameStatus)
{
	this->gameStatus = gameStatus;
}