#include "field.h"

int field::getLocationX()
{
    return this->x;
}

int field::getLocationY()
{
    return this->y;
}

string field::getState()
{
    return this->state;
}

vector<string> field::getStateOptions()
{
    return this->stateOptions;
}

int field::getNumberOfBombsNearby()
{
    return this->numberOfBombsNearby;
}

bool field::getIsBomb()
{
    return this->isBomb;
}

void field::setLocationX(int x)
{
    this->x = x;
}

void field::setLocationY(int y)
{
    this->y = y;
}

void field::setState(string state)
{
    this->state = state;
}

void field::setBomb(bool isBomb)
{
    this->isBomb = isBomb;
}

void field::setNumberOfBombsNearby(int numberOfBombs)
{
    this->numberOfBombsNearby = numberOfBombs;
}

