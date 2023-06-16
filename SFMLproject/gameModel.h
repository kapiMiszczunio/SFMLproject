#pragma once
#include "ctime"
#include "enums.h"
#include "vector"
#include <iostream>

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
	std::vector<std::vector<int>> board;

	/*
	* vector of blocks grid
	*/
	std::vector<std::vector<int>> grid;

	/*
	* variable holds enum number of game difficulty
	*/
	difficulty gameDifficulty;

	/*
	* variable holds status of the game
	*/
	continuation gameStatus;

	/*
	* string containing file name
	*/
	std::string difficult;

	/*
	* array containing score from file
	*/
	std::string scoree[5];

public:
	/*
	* destructor of gameModel
	*/
	~gameModel();

	/*
	* function that overwrite file with best scores
	* @param time
	*/
	void updateRanking(std::string time);

	/*
	* function generates board with randomly chosen bombs positions and calculated number of bombs for every field
	*/
	void generateBoard();

	/*
	* function generates basic grid of board
	*/
	void generateGrid();
	//void readHighscore();

	/*
	* @return return of grid of the board in vector
	*/
	std::vector<std::vector<int>> getGrid();

	/*
	* @return returns enum int game difficulty
	*/
	difficulty getGameDifficulty();

	/*
	* @return returns status of the game in int
	*/
	continuation getGameStatus();

	/*
	* @return returns vector of the board
	*/
	std::vector<std::vector<int>> getBoard();

	/*
	* function sets value of the game status
	* @param status of the game in int
	*/
	void setGameStatus(continuation gameStatus);

	/*
	* function sets value of the game diffculty
	* @param difficulty level of game in enum difficulty (easy, medium or hard)
	*/
	void setGameDifficulty(difficulty difficulty);

	/*
	* @return returns int of board size
	*/
	int getBoardSize();

	/*
	* @return number of unrevealed fields
	*/
	int getFieldLeft();
};
