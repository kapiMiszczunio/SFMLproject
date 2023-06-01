#pragma once
#include "ctime"
#include "vector"
#include <iostream>
using namespace std;

class gameModel 
{
private:
	unsigned seed;
	int boardSize;
	int numberOfBombs;
	int fieldLeft;
	int flaggedCells = 0;
	vector<vector<int>> board;
	vector<vector<int>> grid;
	string gameDifficulty;
	int gameStatus;

public:
	~gameModel();
	void generateBoard();
	void generateGrid();
	vector<vector<int>> getGrid();
	string getGameDifficulty();
	int getGameStatus();
	vector<vector<int>> getBoard();
	void setGameStatus(int gameStatus);
	void setGameDifficulty(string difficulty);
	void addFlag();
	void subFlag();
	int getBoardSize();
	int getFieldLeft();
};
