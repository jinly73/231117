#pragma once
#include "Actor.h"
class AMonster : public AActor
{
public:
	AMonster();
	AMonster(int NewX, int NewY, char NewShape = 'M', int NewSortOrder = 300);
	virtual ~AMonster();

	//accessor
	inline int GetX() const { return X; }
	inline int GetY() const { return Y; }

	inline void SetX(int NewX) { X = NewX; }
	inline void SetY(int NewY) { X = NewY; }
};

