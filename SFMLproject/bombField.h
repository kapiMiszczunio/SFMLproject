#pragma once
#include "field.h"

class bombField : public field
{
public:
	bool getIsBomb();
	void setIsBomb(bool isBomb);
};

