#pragma once
#include "ctime"
#include "vector"
#include <iostream>
using namespace std;

class gameModel 
{
private:

	/*
	* variable helps to generate random board
	*/
	unsigned seed;

	/*
	* variable holds board size
	*/
	int boardSize;

	/*
	* variable holds number of bombs
	*/
	int numberOfBombs;

	/*
	* variable holds number of unrevealed cells
	*/
	int fieldLeft;

	/*
	* variable holds number of flags used
	*/
	int flaggedCells = 0;

	/*
	* vector of game board fields generate randomly
	*/
	vector<vector<int>> board;

	/*
	* vector of blocks grid
	*/
	vector<vector<int>> grid;

	/*
	* variable holds string of game difficulty
	*/
	string gameDifficulty;

	/*
	* variable holds status of the game
	*/
	int gameStatus;

public:

	/*
	* destructor of gameModel
	*/
	~gameModel();

	/*
	* function generates board with randomly chosen bombs positions and calculated number of bombs for every field
	*/
	void generateBoard();

	/*
	* function generates basic grid of board
	*/
	void generateGrid();

	/*
	* @return return of grid of the board in vector
	*/
	vector<vector<int>> getGrid();

	/*
	* @return returns string game difficulty
	*/
	string getGameDifficulty();

	/*
	* @return returns status of the game in int
	*/
	int getGameStatus();

	/*
	* @return returns vector of the board
	*/
	vector<vector<int>> getBoard();

	/*
	* function sets value of the game status
	* @param status of the game in int
	*/
	void setGameStatus(int gameStatus);

	/*
	* function sets value of the game diffculty
	* @param difficulty level of game in int (1, 2 or 3)
	*/
	void setGameDifficulty(string difficulty);

	/*
	* @return returns int of board size
	*/
	int getBoardSize();

	/*
	* @return number of unrevealed fields
	*/
	int getFieldLeft();
};
