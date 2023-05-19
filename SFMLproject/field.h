#pragma once
#include <iostream>
#include <vector>

using namespace std;

class field
{
private:
	int x;
	int y;
	string state = "closed";
	vector<string> stateOptions = {"flagged","closed","opened"};
	bool isBomb;
	int number;
	int numberOfBombsNearby;

public:
	int getLocationX();
	int getLocationY();
	string getState();
	vector<string> getStateOptions();
	int getNumberOfBombsNearby();
	bool getIsBomb();
	void setLocationX(int x);
	void setLocationY(int y);
	void setState(string state);
	void setBomb(bool isBomb);
	void setNumberOfBombsNearby(int numberOfBombs);
};

